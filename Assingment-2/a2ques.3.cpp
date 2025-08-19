#include <iostream>
using namespace std;

int findMissingLinear(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        if (arr[i] != i + 1) {
            return i + 1;
        }
    }
    return size + 1;
}

int main() {
    int n;
    cin >> n;  

    int arr[n-1 ];
    for (int i = 0; i < n-1 ; i++) {
        cin >> arr[i];
    }

    int missing = findMissingLinear(arr, n-1 );
    cout<< missing << endl;

    return 0;
}