#include<iostream>
using namespace std;
int main(){
    int k;
    cout<<"enter the value of k : ";
    cin>>k;
    int count=0;
    int arr[6]={1,4,6,5,3,2};
    for(int i=0;i<=5;i++){
        for(int j=i+1;j<=5;j++){
            if(abs(arr[i]-arr[j])==k ){
                count++;
            }
        }
    }
    cout<<count;
}

