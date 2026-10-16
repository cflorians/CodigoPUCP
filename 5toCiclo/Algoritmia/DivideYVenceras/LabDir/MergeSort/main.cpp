#include <algorithm>
#include <iostream>
using namespace std;

void merge(int arr[], int ini, int mid, int fin) {
    int n1 = mid - ini + 1;
    int n2 = fin - mid;

    int temp[100000];
    int i=0, j=mid+1, k = ini; // i recorre la mita izquierda y j la mitad derecha

    while (i<=mid and j <= fin) { // mientras ambas mitades tengan elementos por fusionar, fusiono
        // ordenamiento fusion entre arreglos
        // sobreescribe esto: temp
        if (arr[i] <= arr[j]) {
            // cogemos el dato i
            temp[k++] = arr[i++];
        }
        else{
            // cogemos el dato j
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid) temp[k++] = arr[i++]; // si es que el i todavia falta avanzar seguimos
    while (j <= fin) temp[k++] = arr[j++]; // igualmente con el j

    for (int x=ini; x<=fin; x++) {
        arr[x] = temp[x];
    }
}

void merge_sort(int arr[], int ini, int fin) {
    // CASO BASE
    if (ini >= fin) return;
    int mid = (ini + fin)/2;
    merge_sort(arr, ini, mid);
    merge_sort(arr, mid+1, fin);
    merge(arr, ini, mid, fin);
}

int main() {
    int arr[] = {5,3,1,9,2,7,4,6};
    int n = sizeof(arr)/sizeof(arr[0]);

    merge_sort(arr, 0, n-1);

    for (int i = 0; i < n; i++) {
        cout<<arr[i]<<" ";
    }
    cout << endl;

    return 0;
}
