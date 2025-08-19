#include <iostream>
using namespace std;


void insertion(int *&arr, int &n) {
    int pos, val;
    cout << "Enter position to insert : ";
    cin >> pos;
  
    cout << "Enter value to insert: ";
    cin >> val;

    int *newArr = new int[n + 1];
    for (int i = 0; i < pos - 1; i++) {
        newArr[i] = arr[i];
    }
    newArr[pos - 1] = val;
    for (int i = pos; i <= n; i++) {
        newArr[i] = arr[i - 1];
    }

    delete[] arr;
    arr = newArr;
    n++;
}

void deletion(int *&arr, int &n) {
    int pos;
    cout << "Enter position to delete : ";
    cin >> pos;
 
    int *newArr = new int[n - 1];
    for (int i = 0; i < pos - 1; i++) {
        newArr[i] = arr[i];
    }
    for (int i = pos; i < n; i++) {
        newArr[i - 1] = arr[i];
    }

    delete[] arr;
    arr = newArr;
    n--;
}

void linearSearch(int *arr, int n) {
    int val;
    cout << "Enter value to search: ";
    cin >> val;
    bool found = false;

    for (int i = 0; i < n; i++) {
        if (arr[i] == val) {
            cout << "Found at index " << i << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "Value not found." << endl;
    }
}

int main() {
    int *arr = nullptr;
    int n = 0;

    cout << "Enter size of array: ";
    cin >> n;
    arr = new int[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }


    int c;
    cout<<"enter 1 for deletion : 2 for insertion : 3 for linearsearch : ";
    cin>>c;
    if(c==1){
       deletion(arr, n);
    }
    if(c==2){
       insertion(arr, n);
    }
    if(c==3){
       linearSearch(arr, n); 
    }
  

    cout << endl<<"Array elements: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;  // Free memory

    return 0;
}