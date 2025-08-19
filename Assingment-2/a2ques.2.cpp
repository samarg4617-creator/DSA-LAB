#include<iostream>
using namespace std;

void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void bubblesort(int arr[],int n){
     for(int i=0;i<=n-2;i++){
        for(int j=0;j<=n-2-i;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
      for(int i=0;i<=6;i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int arr[7]={64,34,25,12,22,11,90};
    bubblesort(arr,7);

    }