#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<=n-1;i++){
        cin>>arr[i];
    }
    int target;
    cin>>target;

    int low=0;int high=n-1;
    while(low<=high){  
    int mid=(low+high)/2;
    if(arr[mid]==target){
        cout<<"the index of the element is : "<<mid;
        break;
    }
    else if(arr[mid]>target){
        high=mid-1;
    }
    else{
        low=mid+1;
    }

    }
    
    }