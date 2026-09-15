#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// LIS (longest increasing subsequence)
int lis(vector<int> &x, int n) {
    vector <int> dp(n,1); // todos parten del caso base que es 1
    for (int i = 1; i < n; i++) { // para cada elemento menso el primero
        for (int j = 0; j < i; j++) { // se revisan todos los anteriores al elemento i
            if (x[j] < x[i]) { // se puede agregar a la subsecuencia?
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
    }
    return *max_element(dp.begin(), dp.end()); // el dp[i] mayor de toda la tabla
}

int knapsack(vector<int> &pesos, vector<int> &valor, int n, int W) {
    int dp[n+1][W+1]{};

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= W; j++) {
            dp[i][j] = dp[i-1][j];
            if (pesos[i-1] <= j) { // si es que entra
                dp[i][j] = max(dp[i][j], valor[i-1] + dp[i-1][j-pesos[i-1]]);
            }
        }
    }
    return dp[n][W];
}

int main() {

    vector<int> x{-7,10,9,2,3,8,8,1};
    int n = x.size();

    cout << lis(x, n) << endl;

    vector<int> pesos{2,1,3,2};
    vector<int> valor{12,10,20,15};
    cout << knapsack(pesos, valor, 4, 5) << endl;

    return 0;
}
