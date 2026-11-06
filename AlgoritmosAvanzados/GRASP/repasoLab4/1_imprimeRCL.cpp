#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const double alfa = 0.3;

struct Objeto
{
	char id;
	int valor;
};

bool comparaMaximizar(const Objeto& a, const Objeto& b){
	return a.valor > b.valor;
}

bool comparaMinimizar(const Objeto& a, const Objeto& b){
	return a.valor < b.valor;
}

void imprimeRCL(const vector<Objeto>& v, double umbral, int modo){
	// modo 0 es maximizar
	// modo 1 es minimizar
	cout << "RCL: ";
	if (modo == 0){
		for (int i = 0; v[i].valor >= umbral; ++i){
			cout << v[i].id << '(' << v[i].valor << ") ";
		}
		cout << endl;
		return;
	}
	
	for (int i = 0; v[i].valor <= umbral; ++i){
		cout << v[i].id << '(' << v[i].valor << ") ";
	}
	cout << endl;
	return;
}

int main(){
	vector <Objeto> objetos;
	int beta, tau;
	double umbral;

	objetos.push_back({'A', 10});
	objetos.push_back({'B', 40});
	objetos.push_back({'C', 25});
	objetos.push_back({'D', 35});
	objetos.push_back({'E', 5});
	objetos.push_back({'F', 30});

	// MODO MAXIMIZAR
	sort(objetos.begin(), objetos.end(), comparaMaximizar);
	beta = objetos.front().valor;
	tau = objetos.back().valor;
	umbral = beta - alfa*(beta - tau);

	cout << "MAXIMIZAR" << endl;
	cout << "Beta = " << beta << "  Tau = " << tau << "  Umbral = " << umbral << endl;
	imprimeRCL(objetos, umbral, 0);


	// MODO MINIMIZAR
	sort(objetos.begin(), objetos.end(), comparaMinimizar);
	beta = objetos.front().valor;
	tau = objetos.back().valor;

	umbral = beta + alfa*(tau - beta);

	sort(objetos.begin(), objetos.end(), comparaMinimizar);
	cout << "MAXIMIZAR" << endl;
	cout << "Beta = " << beta << "  Tau = " << tau << "  Umbral = " << umbral << endl;
	imprimeRCL(objetos, umbral, 1);

	return 0;
}