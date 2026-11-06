#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <climits>
using namespace std;

const int ITERACIONES = 1000;
const double alfa = 0.2;
const int capacidad = 60;

struct Objeto
{
	char id;
	int valor;
};

void cargaDatos(vector<Objeto>& v){
	v.push_back({'A', 10});
	v.push_back({'B', 40});
	v.push_back({'C', 25});
	v.push_back({'D', 35});
	v.push_back({'E', 5});
	v.push_back({'F', 30});
}

bool compara(const Objeto& a, const Objeto& b){
	return a.valor > b.valor;
}

bool valida(int pesoActual, int pesoAColocar){
	return (pesoActual + pesoAColocar) <= capacidad;
}

int tamRCLmax(const vector<Objeto>& v){
	int beta, tau;
	double umbral;
	int tam = 0;

	beta = v.front().valor;
	tau = v.back().valor;
	umbral = beta - alfa*(beta - tau);

	for(tam = 0; tam < (int)v.size() and v[tam].valor >= umbral; tam++);

	return tam;
}

vector<Objeto> filtraFactibles(const vector<Objeto>& v, int pesoActual){
	vector <Objeto> filtrado;
	for (const Objeto& o : v){
		if (valida(pesoActual, o.valor)) filtrado.push_back(o);
	}
	return filtrado;
}

int construir(vector<Objeto> v, vector<Objeto>& solucion){
	vector <Objeto> factibles;
	int peso = 0, k, indice, indiceV;
	while(true){
		factibles = filtraFactibles(v, peso);
		if (factibles.empty()) break;
		k = tamRCLmax(factibles);
		indice = rand() % k;

		// si llega aca es porque entra, entonces lo metemos
		solucion.push_back(factibles[indice]);
		peso += factibles[indice].valor;
		// lo borramos de la lista
		// buscando en v el valor
		indiceV = 0;
		for (const Objeto& o : v){
			if (o.id == factibles[indice].id) {
				v.erase(v.begin() + indiceV);
				break;
			}
			indiceV++;
		}
	}
	return peso;
}

int grasp(const vector <Objeto>& v, vector <Objeto>& mejorSol){
	int pesoActual, mejorPeso = INT_MIN;
	for(int i = 0; i < ITERACIONES; i++){
		vector <Objeto> solucion;

		pesoActual = construir(v, solucion);
		
		// ahora comparamos con la solucion anterior
		if (pesoActual > mejorPeso){
			// si es que el peso de esta solucion es mejor 
			// volcamos en un vector de mejor arreglo
			mejorSol = solucion;
			mejorPeso = pesoActual;
		}
	}
	return mejorPeso;
}

int main(){
	vector <Objeto> v;
	vector <Objeto> mejorSol;
	int mejorPeso;

	srand(time(NULL));
	
	cargaDatos(v);
	sort(v.begin(), v.end(), compara);

	mejorPeso = grasp(v, mejorSol);

	// ahora mostramos la solucion
	cout << "Mejor solucion: ";
	for (const Objeto& o : mejorSol){
		cout << o.id << ' ';
	}
	cout << endl;

	cout << "Valor total: " << mejorPeso << '/' << capacidad << endl;

	return 0;
}