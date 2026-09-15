#include <iostream>
#include <vector>
using namespace std;

int fibonacci(int n) {
    vector<int> F(n+1); // definimos un vector de tamaño n+1
    F[0] = 0; // datos conocidos de fibonacci
    if (n >= 1) F[1] = 1; // funcionan como un "Caso base"

    for (int i=2; i<=n; i++) {
        F[i] = F[i-1] + F[i-2];
    }

    return F[n];
}

void coinRow(int C[], int n) {
    vector<int> F(n+1);
    F[0] = 0;
    F[1] = C[0];

    for (int i=2; i<=n; i++) {
        F[i] = max(C[i-1] + F[i-2], F[i-1]);
    }

    for (int i=0; i<=n; i++) {
        cout << F[i] << (i==n ? '\n' : ' ');
    }

    //show coins
    for (int i=n; i>0; i--) {
        if (F[i] != F[i-1]) {
            cout << C[i-1] << (i==1 ? '\n' : ' ');
            i--;
        }
    }
}

int main() {

    // int n = 5;
    // cout << "F(" << n << ") = " << fibonacci(n) << endl;

    int C[] = {5,1,2,10,6,2};
    int n = sizeof(C)/sizeof(C[0]);

    coinRow(C, n);

    return 0;
}
