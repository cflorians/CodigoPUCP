```
Inicio algoritmo_genetico
	Generar poblacion inicial
	Mientras (!condicion_parada)
		1.  Calcular supervivencia 			// fitness
			Seleccionar						// ruleta
		2.  Aplicar operador genetico 		// recombinación
		3.  Generar la poblacion			// t + 1
	Fin Mientras
Fin algoritmo_genetico
```

# Funciones
## mochilaAG
``` cpp
void mochilaAG(int *paq,int n,int peso) {
    vector<vector<int>> poblacion;
    // Genera la poblacion inicial de forma aleatoria
    generaPoblacion(poblacion, vector, tamVector, limitante);

    for(int i=0;i<ITERACIONES;i++) {
    	// Para cada generación definimos a los padres
        vector<vector<int>>padres;
        // impresion de la poblacion
        muestrapoblacion(poblacion, vector);
        cout << endl;
        // Selecciona a los más aptos
        seleccion(poblacion,padres,vector,tamVector,peso);
        // Genera a los nuevos hijos
        casamiento(poblacion,padres,vector,peso);
        // Elimina duplicados
        mataclon(poblacion);
        // Muta
        mutacion((poblacion),padres,vector,peso);
        // Invierte un gen
        inversion(poblacion,padres,vector,peso);

        // Generamos una nueva poblacion
        regenerapoblacion(poblacion,vector,peso);
        // impresión de la poblacion
        muestrapoblacion(poblacion,vector);
        // impresión de la poblacion
        muestramejor(poblacion,vector,peso);
    }
}
```

### generapoblacion()
``` cpp
void generapoblacion(vector<vector<int>> &poblacion,int *paq,int n,int peso) {
    int cont=0;
    srand(time(NULL));
    // Hasta tener NUMIND individuos
    while (cont<NUMIND) {
        vector<int> individuo;
        // Genera un cromosoma aleatorio (CAMBIAR si los genes no son 0/1)
        for (int i=0; i<n; i++)
            individuo.push_back(rand()%2);
        // Solo se agrega si no es una aberración
        if (!aberracion(individuo,peso,paq)) {
            poblacion.push_back(individuo);
            cont++;
        }
    }
}
```

### seleccion(poblacion, &padres, n, peso, ...)
``` cpp
void seleccion(vector<vector<int>>poblacion,vector<vector<int>> &padres,int *paq,int n,int peso) {
    int ruleta[120];
    fill(ruleta,ruleta+120,-1);
    vector<int>supervivencia;
    // Porcentaje de supervivencia de cada individuo
    calculasupervivencia(poblacion,supervivencia,paq,n,peso);
    // Reparte los tickets y devuelve cuántos generó
    int tickets=cargaruleta(supervivencia,ruleta);
    // Cantidad de padres a elegir
    int npadres=round(poblacion.size()*TSELECCION);

    // Gira la ruleta npadres veces
    for (int i=0;i<npadres;i++) {
        int ticket=rand()%tickets;
        padres.push_back(poblacion[ruleta[ticket]]);
    }
}
```

#### calculafitness
``` cpp
int calculafitness(vector<int>cromo,int *paq) {
    int sumap=0;
    // Función objetivo (CAMBIAR según lo que pida el problema)
    for(int i=0;i<cromo.size();i++)
        sumap+=cromo[i]*paq[i];
    return sumap;
}
```

#### calculasupervivencia
``` cpp
void calculasupervivencia(vector<vector<int>>poblacion,vector<int> &supervivencia,int *paq,int n,int peso) {
    int sumafitness=0;
    // Suma de los fitness de toda la población
    for(int i=0;i<poblacion.size();i++)
        sumafitness+=calculafitness(poblacion[i],paq);
    // SI = fitness del individuo / suma de fitness (en %)
    for (int i=0;i<poblacion.size();i++) {
        int superfit=round(100*(double)calculafitness(poblacion[i],paq)/sumafitness);
        supervivencia.push_back(superfit);
    }
}
```

#### int cargaruleta(supervivencia, ruleta)
``` cpp
int cargaruleta(vector<int>supervivencia,int *ruleta) {
    int cont=0;
    // Cada casilla guarda el índice del individuo (tantas casillas como tickets tenga)
    for (int i=0;i<supervivencia.size();i++)
        for (int j=0;j<supervivencia[i];j++)
            ruleta[cont++]=i;
    // Cantidad de tickets generados
    return cont;
}
```

### casamiento()
``` cpp
void casamiento(vector<vector<int>> &poblacion,vector<vector<int>>padres,int *paq,int peso) {
    // Cruza todas las parejas de padres
    for(int i=0;i<padres.size();i++)
        for(int j=0;j<padres.size();j++) {
            if (i!=j) {
                vector<int>hijo;
                creahijo(padres[i],padres[j],hijo);
                // Solo se agrega si no es una aberración
                if (!aberracion(hijo,peso,paq))
                    poblacion.push_back(hijo);
            }
        }
}
```

#### creahijo(padre, madre, &hijo)
``` cpp
void creahijo(vector<int>padre,vector<int>madre,vector<int>&hijo) {
    // Punto de corte
    int posi=round(padre.size()*PCASAMIENTO);
    // Primeros genes del padre
    for (int i=0;i<posi;i++)
        hijo.push_back(padre[i]);
    // Resto de genes de la madre
    for (int i=posi;i<madre.size();i++)
        hijo.push_back(madre[i]);
}
```

#### aberracion() 
``` cpp
bool aberracion(vector<int>ind,int peso,int *paq) {
    // Verifica que el individuo no incumpla la restricción (CAMBIAR según el problema)
    return calculafitness(ind,paq)>peso;
}
```

### mataclon()
``` cpp
void mataclon(vector<vector<int>> &poblacion) {
    // La key es única: si dos individuos son iguales solo queda uno
    map<int,vector<int>> indunicos;
    for(int i=0;i<poblacion.size();i++)
        indunicos[decimal(poblacion[i])]=poblacion[i];
    // Se reconstruye la población solo con los únicos
    poblacion.clear();
    for(map<int,vector<int>>::iterator it=indunicos.begin();it!=indunicos.end();it++)
        poblacion.push_back(it->second);
}
// decimal() convierte el cromosoma binario a número (sum ind[i]*2^i)
```

### mutacion()
``` cpp
void mutacion(vector<vector<int>> &poblacion,vector<vector<int>>padres,int *paq,int peso) {
    // Cantidad de genes a mutar
    int nmutaciones=round(padres[0].size()*TMUTACION);
    for (int i=0;i<padres.size();i++) {
        int cont=0;
        while (cont<nmutaciones) {
            // Gen aleatorio (CAMBIAR si el problema indica qué genes mutan)
            int gen=rand()%padres[i].size();
            // Cambia 0->1 o 1->0 (CAMBIAR si son números enteros)
            if (padres[i][gen]==0) padres[i][gen]=1;
            else padres[i][gen]=0;
            cont++;
        }
        // Solo se agrega si no es una aberración
        if (!aberracion(padres[i],peso,paq))
            poblacion.push_back(padres[i]);
    }
}
```

### inversion()
``` cpp
void inversion(vector<vector<int>> &poblacion,vector<vector<int>>padres,int *paq,int peso) {
    for (int i=0;i<padres.size();i++) {
        // Invierte todos los genes (CAMBIAR si son números enteros)
        for (int j=0;j<padres[i].size();j++) {
            if (padres[i][j]==0) padres[i][j]=1;
            else padres[i][j]=0;
        }
        // Solo se agrega si no es una aberración
        if (!aberracion(padres[i],peso,paq))
            poblacion.push_back(padres[i]);
    }
}
```

### regenera poblacion
``` cpp
void regenerapoblacion(vector<vector<int>> &poblacion,int *paq,int peso) {
    // Elimina duplicados
    mataclon(poblacion);
    // Ordena de mayor a menor fitness
    sort(poblacion.begin(), poblacion.end(),
         [paq](const vector<int>& a, const vector<int>& b) {
            return calculafitness(a,paq) > calculafitness(b,paq);
         });
    // Se queda solo con los NUMIND mejores
    if (poblacion.size()>NUMIND)
        poblacion.erase(poblacion.begin()+NUMIND,poblacion.end());
}
```
