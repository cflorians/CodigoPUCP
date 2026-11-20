#include <iostream>
#include <iomanip>
#include <vector>
#include <ctime>
#include <cmath>
#include <algorithm>
#include <map>
using namespace std;

struct Paquete{
	int id;
	int peso;
	int ganancia;
};

struct Dron{
	int id;
	int capacidad;
};

#define POBLACION_INICIAL 10
#define TASA_SELECCION 0.4
#define TASA_CASAMIENTO 0.5
#define ITERACIONES 10

void cargaDatos(vector<Paquete>& paq, vector<Dron>& drones){
	paq.push_back({1,4,40});
	paq.push_back({2,6,55});
	paq.push_back({3,3,20});
	paq.push_back({4,8,70});
	paq.push_back({5,5,45});
	paq.push_back({6,2,15});
	paq.push_back({7,7,60});

	drones.push_back({1,10});
	drones.push_back({2,12});
	drones.push_back({3,8});
}

bool aberracion(const vector<int>& individuo, 
				const vector<Paquete>& paquetes,
				const vector<Dron>& drones){
	// una aberracion en este problema es:
	// 1. tiene mas de 3 paquetes en un mismo dron
	// 2. supera la capacidad de carga del dron
	// 3. que los paquetes 2 y 4 esten en el mismo dron
	// 4. si un paquete esta en mas de un dron

	int idx, cantPaquetesDron, pesoTotalDron;
	// 1. el mismo dron tiene mas de 3 paquetes
	// 2. supera la capacidad de carga del dron
	for (int i = 0; i < drones.size(); ++i){
		// revisamos dron por dron
		cantPaquetesDron = 0;
		pesoTotalDron = 0;
		for (int j = 0; j < paquetes.size(); ++j){
			// calculamos el indice teniendo en cuenta el desplazamiento
			// donde i es el indice de dron y j el indice de paquete
			idx = i * paquetes.size() + j;
			// si es que el valor es 1, significa
			// que ese paquete esta en el dron
			if (individuo[idx]) {
				cantPaquetesDron++;
				pesoTotalDron += paquetes[j].peso;
				// si ya no cumple las condiciones, retornamos true
				if (cantPaquetesDron > 3 or pesoTotalDron > drones[i].capacidad){
					return true;
				}
			}
		}
	}

	// 3. revisamos que los paquetes 2 y 4 no esten en el mismo dron
	// posicion del paquete 2 -> indice = 1
	// posicion del paquete 4 -> indice = 3
	// en individuo, en cada dron, solamente o el indice 1 o el 3 puede
	// ser 1, no ambos a la vez
	// revisamos dron por dron
	for (int i = 0; i < drones.size(); ++i){
		idx = i * paquetes.size();
		// en este caso, idx es el desplazamiento del dron
		if (individuo[idx + 1] == 1 and individuo[idx + 3] == 1){
			return true;
		}
	}

	// 4. si un paquete esta en mas de un dron
	// definimos nuestro arreglo de colocados
	vector<int> llevados(paquetes.size(), 0);
	int p;
	// revisamos ahora todo el arreglo individuo
	for (int i = 0; i < individuo.size(); ++i){
		// que paquete representa cada gen
		p = i % paquetes.size();
		if (individuo[i] == 1){
			if (llevados[p] == 1) return true;
			llevados[p] = 1;
		}
	}

	return false;
}

void generaPoblacion(vector<vector<int>>& poblacion,
					 const vector<Paquete> paquetes,
					 const vector<Dron>& drones){
	int cont = 0;
	srand(time(NULL));
	while (cont < POBLACION_INICIAL){
		vector<int> individuo;
		for (int i = 0; i < paquetes.size()*drones.size(); ++i){
			// se genera aleatoriamente un individuo
			individuo.push_back(rand()%2);
		}
		if (!aberracion(individuo, paquetes, drones)){
			poblacion.push_back(individuo);
			cont++;
		}
	}
}

int calculafitness(vector<int> cromosoma, const vector<Paquete> paq){
	int sumap = 0, p;
	for (int i = 0; i < cromosoma.size(); ++i){
		p = i % paq.size();
		sumap += cromosoma[i]*paq[p].ganancia;
	}
	return sumap;
}

void calcularSupervivencia(vector<vector<int>>poblacion,
    					  vector<int> &supervivencia,
    					  const vector<Paquete> paquetes,
    					  const vector<Dron>& drones){
	int sumaFitness = 0;

	for (int i = 0; i < poblacion.size(); i++){
		sumaFitness += calculafitness(poblacion[i], paquetes);
	}
	for (int i = 0; i < poblacion.size(); i++){
		int superfit;
		superfit = round(100*(double)calculafitness(poblacion[i], paquetes)/sumaFitness);
		supervivencia.push_back(superfit);
	}
}

int cargaRuleta(const vector<int>& supervivencia, vector<int>& ruleta){
	int cont = 0;
	for (int i = 0; i < supervivencia.size(); ++i){
		for (int j = 0; j < supervivencia[i]; j++){
			ruleta[cont++] = i;
		}
	}
	return cont;
}

void creaHijo(vector<int>padre,vector<int>madre,
    vector<int>&hijo){

	int posi = round(padre.size()*TASA_CASAMIENTO);

	for (int i=0; i<posi; i++){
		hijo.push_back(padre[i]);
	}
	for (int i=posi; i<madre.size(); i++){
		hijo.push_back(madre[i]);
	}

}

void casamiento(vector<vector<int>>& poblacion,
				vector<vector<int>> padres,
				const vector<Paquete>& paquetes,
			   	const vector<Dron>& drones){

	for (int i = 0; i < padres.size(); ++i)
	{
		for (int j = 0; j < padres.size(); ++j)
		{
			if (i != j){
				vector <int> hijo;
				creaHijo(padres[i], padres[j], hijo);
				if (!aberracion(hijo, paquetes, drones)){
					poblacion.push_back(hijo);
				}
			}
		}
	}
}

void seleccion(vector<vector<int>> poblacion,
			   vector<vector<int>>& padres,
			   const vector<Paquete>& paquetes,
			   const vector<Dron>& drones){
	vector<int> ruleta(120, -1);
	vector<int> supervivencia;
	calcularSupervivencia(poblacion, supervivencia, paquetes, drones);
	int cantTickets = cargaRuleta(supervivencia, ruleta);
	int nPadres = round(poblacion.size()*TASA_SELECCION);

	for (int i = 0; i < nPadres; ++i)
	{
		int ticket = rand()%cantTickets;
		if (ruleta[ticket] != -1){
			padres.push_back(poblacion[ruleta[ticket]]);
		}
	}
}

int decimal(vector<int>ind) {
    int num=0;
    for (int i=0;i<ind.size();i++)
        num+=ind[i]*pow(2,i);
    return num;
}

void mataClon(vector<vector<int>>& poblacion){
	map<int, vector<int>> indunicos;

	for (int i=0; i<poblacion.size(); i++){
		int dec = decimal(poblacion[i]);
		indunicos[dec] = poblacion[i];
	}
	poblacion.clear();
	for(map<int,vector<int>>::iterator it=indunicos.begin();
        it!=indunicos.end();it++) 
	{
        poblacion.push_back(it->second);
    }
}

void regeneraPoblacion(vector<vector<int>>& poblacion,
			   		   const vector<Paquete>& paquetes,
			   		   const vector<Dron>& drones){
	mataClon(poblacion);

	sort(poblacion.begin(), poblacion.end(),
        [&paquetes](const vector<int>& a, const vector<int>& b) {
            int suma=0, sumb=0;
            for(int i=0;i<a.size();i++)
                suma += calculafitness(a, paquetes);
            for(int i=0;i<b.size();i++)
                sumb += calculafitness(b, paquetes);

            return suma > sumb;
        });
	if (poblacion.size()>POBLACION_INICIAL)
        poblacion.erase(poblacion.begin()+POBLACION_INICIAL,poblacion.end());
}

int muestramejor(vector<vector<int>> poblacion,
        const vector<Paquete>& p, const vector<Dron>& d){
    int mejor=0;
    // puede mejorarse ya que esta muestra mejor lo busca en toda la poblaciÃ³n
    // desde luego se puede asumir que es la posiciÃ³n 0 para nuestro caso
    for(int i=0;i<poblacion.size();i++)
        if(calculafitness(poblacion[mejor],p)<calculafitness(poblacion[i],p))
            mejor=i;

    // aqui ya tenemos a la mejor solucion, ahora toca imprimirla
   	vector<int> asignados(p.size(),0);
   	int ip;
   	int pesoUsado, ganancia;
   	int totalGanacia = 0;
    for (int i = 0; i < d.size(); ++i)
    {
    	cout << left << setw(6) << d[i].id;
    	pesoUsado = 0;
    	ganancia = 0;
    	for (int j = 0; j < p.size(); ++j)
    	{
    		ip = i * p.size() + j;
    		if (poblacion[mejor][ip] == 1){
    			cout << p[j].id << ' ';
    			asignados[j] = 1;
    			pesoUsado += p[j].peso;
    			ganancia += p[j].ganancia;
    		}
    	}
    	cout << right << setw(6) << pesoUsado;
		cout << right << setw(6) << ganancia << endl;
    	totalGanacia += ganancia;
    }

    cout << "Sin asignar  ";
    for (int i = 0; i < asignados.size(); ++i)
    {
    	if (asignados[i] == 0){
    		cout << p[i].id << ' ';
    	}
    }
    cout << endl;

    cout << "Total ganancia: " << totalGanacia << endl;

    return 1;
}

void dronesAG(const vector<Paquete>& p, const vector<Dron>& d){
	vector<vector<int>> poblacion;
	generaPoblacion(poblacion, p, d);
	for (int i = 0; i < ITERACIONES; ++i){
		vector<vector<int>> padres;
		seleccion(poblacion, padres, p, d);
		casamiento(poblacion, padres, p, d);
		regeneraPoblacion(poblacion, p, d);
	}
	muestramejor(poblacion, p, d);
}

int main(void){

	vector<Paquete> paquetes;
	vector<Dron> drones;

	cargaDatos(paquetes, drones);

	dronesAG(paquetes, drones);

	return 0;
}