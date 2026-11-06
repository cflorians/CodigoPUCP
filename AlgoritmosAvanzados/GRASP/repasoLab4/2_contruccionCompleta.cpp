#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;

const double alfa = 0.5;

struct Objeto
{
	char id;
	int valor;
};

bool compara(const Objeto& a, const Objeto& b){
	return a.valor > b.valor;
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

void imprimeRCL(const vector<Objeto>& v, int k){
	cout << " RCL=[";
	for(int i=0; i<k; i++){
		cout << v[i].id << (i == k-1 ? ']':' ');
	}
}

void imprimePaso(const vector<Objeto>& v, int indice, int k, int paso){
	int beta, tau;
	double umbral;

	beta = v.front().valor;
	tau = v.back().valor;
	umbral = beta - alfa*(beta - tau);

	cout << "Paso " << paso << ": ";
	cout << "beta=" << beta;
	cout << " tau=" << tau;
	cout << " umbral=" << umbral;
	imprimeRCL(v, k);
	cout << " -> elegido " << v[indice].id << endl;
}

int main(){
	vector <Objeto> v;
	int k, indice, paso = 1;

	srand(time(NULL));

	v.push_back({'A', 10});
	v.push_back({'B', 40});
	v.push_back({'C', 25});
	v.push_back({'D', 35});
	v.push_back({'E', 5});
	v.push_back({'F', 30});

	sort(v.begin(), v.end(), compara);
	while(not v.empty()){
		k = tamRCLmax(v);
		indice = rand() % k;
		imprimePaso(v, indice, k, paso);
		paso ++;
		v.erase(v.begin() + indice);
	}

	return 0;
}