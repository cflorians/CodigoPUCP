#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void solve() {
    
}

int main() {

    vector<int> A = {3,1,4,2,5,1};

    sort(A.begin(), A.end());
    for (auto i : A) {
        cout << i << " ";
    }

    return 0;
}
