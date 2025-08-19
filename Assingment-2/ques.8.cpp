#include <iostream>
#include <string>
                  
using namespace std;
                  
int main() {
  //Write a program to count the total number of distinct elements in an array of length n.


  int arr[9]={2,2,1,3,6,1,9,8,7};
  int n=9;
  int ans=9;

  for(int i=0;i<n;i++)
  {
    for(int j=0; j<n;j++)
    {
        if(arr[j]==arr[i]&&j!=i)
        {
            ans--;
            break;
        }

    }
  }
  cout<<ans;
    return 0;
}