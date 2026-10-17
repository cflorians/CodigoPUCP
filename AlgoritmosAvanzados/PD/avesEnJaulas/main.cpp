#include <iostream>
using namespace std;

const int STATES = 3;
const int N_MAX = 100;

void solve(int n) {
    int dp[STATES][N_MAX+1];
    dp[0][1] = 1;
    dp[1][1] = 1;
    dp[2][1] = 1;

    for (int i = 2; i <= N_MAX; i++) {
        dp[0][i] = dp[0][i-1] + dp[1][i-1] + dp[2][i-1];
        dp[1][i] = dp[0][i-1] + dp[2][i-1];
        dp[2][i] = dp[0][i-1] + dp[1][i-1];
    }

    int result = dp[0][n] + dp[1][n] + dp[2][n];
    cout << result << endl;
}

int main(int argc, char** argv) {

    // n es la cantidad de filas
    solve(2);

    return 0;
}
