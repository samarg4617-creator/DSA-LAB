#include<iostream>
using namespace std;

void removeDuplicates(int arr[] , int &n){
    int i =0;
    for(int j= i ; i<n ; j++){
        if(arr[j] != arr[i]){
            arr[i+1] = arr[j];
            i++;
        }
        else{
            n--;
        }
    }
}
int main(){
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    removeDuplicates(arr ,n);
    cout << endl<<"Array after removing duplicates:"<<endl;

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}