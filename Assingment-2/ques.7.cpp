#include <iostream>
#include <string>
                  
using namespace std;
                  
int main() {
    //Let A[1 …. n] be an array of n real numbers. A pair (A[i], A[j ]) is said to be an inversion if these numbers are out of order, i.e., i < j but A[i]>A[j ]. Write a program to count the number of inversions in an array
    int n=5;
    int ans=0;
    int arr[5]={1,3,2,6,5};

    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[i]>arr[j])
            {ans++;}
        } 
    }

    cout<<ans;
    return 0;
}