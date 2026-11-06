#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <climits>
using namespace std;

const int ITERACIONES = 1000;
const double alfa = 0.5;
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

int construir(vector<Objeto> v, vector<Objeto>& solucion){
	int peso = 0, k, indice;
	while(not v.empty()){
		k = tamRCLmax(v);
		indice = rand() % k;
		
		if (not valida(peso, v[indice].valor)) break;

		// si llega aca es porque entra, entonces lo metemos
		solucion.push_back(v[indice]);
		peso += v[indice].valor;
		// lo borramos de la lista
		v.erase(v.begin() + indice);
	}
	return peso;
}

int main(){
	vector <Objeto> v;
	vector <Objeto> mejorSol;
	int pesoActual, mejorPeso = INT_MIN;
	srand(time(NULL));
	
	cargaDatos(v);
	sort(v.begin(), v.end(), compara);

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

	// ahora mostramos la solucion
	cout << "Mejor solucion: ";
	for (const Objeto& o : mejorSol){
		cout << o.id << ' ';
	}
	cout << endl;

	cout << "Valor total: " << mejorPeso << '/' << capacidad << endl;

	return 0;
}