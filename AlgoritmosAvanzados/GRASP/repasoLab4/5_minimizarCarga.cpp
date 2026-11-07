#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstring>
#include <ctime>
using namespace std;

const int ITERACIONES = 1000;
const int nroTrabajadores = 3;
const double alfa = 0.5;

struct Tarea {
	int id;
	int duracion;
};

struct Trabajador {
	vector<Tarea> tareas;
	int carga = 0;
};

void cargaDatos(vector<Tarea>& t){
	t.push_back({1,8});
	t.push_back({2,7});
	t.push_back({3,6});
	t.push_back({4,5});
	t.push_back({5,4});
	t.push_back({6,3});
	t.push_back({7,2});
}

int trabajadorMenorCarga(const vector<Trabajador>& trabajadores){
	int menorCarga = INT_MAX, indiceMenorCarga;
	for (int i=0; i<nroTrabajadores; i++){
		// buscamos al trabajador de menor carga
		if (trabajadores[i].carga < menorCarga){
			indiceMenorCarga = i;
			menorCarga = trabajadores[i].carga;
		}
	}
	// devolvemos el indice del trabajador con menor carga
	return indiceMenorCarga;
}

int tamRCL(const vector<Tarea>& tareas, double umbral){
	int tam = 0;
	while (tam < (int)tareas.size() and tareas[tam].duracion >= umbral) tam++;
	return tam;
}

int construir(vector<Tarea> tareas, vector<Trabajador>& solucion){
	// repetimos mientras haya tareas
	int beta, tau;
	int k, indiceTarea, indiceTrabajador;
	double umbral;
	while (not tareas.empty()){
		beta = tareas.front().duracion;
		tau = tareas.back().duracion;
		umbral = beta - alfa*(beta - tau);

		// armamos el RCL
		k = tamRCL(tareas, umbral);
		indiceTarea = rand() % k;

		// obtenemos el trabajador de menor carga
		indiceTrabajador = trabajadorMenorCarga(solucion);

		// ahora tomamos uno random y lo colocamos en la solucion
		solucion[indiceTrabajador].tareas.push_back(tareas[indiceTarea]);
		solucion[indiceTrabajador].carga += tareas[indiceTarea].duracion;

		// borramos la tarea de la lista
		tareas.erase(tareas.begin() + indiceTarea);
	}

	// ahora calculamos el makespan
	int makespan = 0;
	for (Trabajador t : solucion){
		if (t.carga > makespan) makespan = t.carga;
	}

	return makespan;
}

int grasp(vector<Trabajador>& trabajadores, vector<Tarea> tareas){
	int mejorMakespan = INT_MAX, makespanActual;
	vector<Trabajador> mejorSolucion;
	// hacemos las iteraciones
	for (int i=0; i<ITERACIONES; i++){
		vector<Trabajador> solucion = trabajadores;

		// construimos una solucion
		makespanActual = construir(tareas, solucion);

		// ahora que tenemos el makespanActual
		// lo comparamos con el mejor
		if (makespanActual < mejorMakespan){
			mejorSolucion = solucion;
			mejorMakespan = makespanActual;
		}
	};

	trabajadores = mejorSolucion;
	return mejorMakespan;
}

void imprimeTareasTrabajador(const Trabajador& t){
	string linea = " ";
	for(const Tarea& tarea : t.tareas){
		char tareaID = '0' + tarea.id;
		linea += 'T';
		linea += tareaID;
		linea += ' ';
	};
	cout << left << setw(15) << linea;
}

int main(){
	srand(time(NULL));

	vector<Tarea> tareas;
	vector<Trabajador> trabajadores(nroTrabajadores);
	int mejorMakespan;

	cargaDatos(tareas);
	// como se ha insertado ordenado, no hace falta ordenarlo

	mejorMakespan = grasp(trabajadores, tareas);

	cout << "Mejor makespan: " << mejorMakespan << endl;
	int i = 1;
	for (const Trabajador& trabajador : trabajadores){
		cout << "Trabajador " << i << ": ";
		imprimeTareasTrabajador(trabajador);
		cout << "(carga " << trabajador.carga << ")" << endl;
		i++;
	}

	return 0;
}