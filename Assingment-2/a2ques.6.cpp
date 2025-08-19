#include<iostream>
using namespace std;
int main(){
    int r1;int c1;
    cin>>r1;
    cin>>c1;
    int arr[r1][c1];
    for(int i=0;i<=r1-1;i++){
        for(int j=0;j<=c1-1;j++){
            cin>>arr[i][j];
        }
    }
    int count =0;
    for(int i=0;i<=r1-1;i++){
        for(int j=0;j<=c1-1;j++){
           if(arr[i][j]!=0){
            count++;
           }
        }
    }

    int mat[count][3];
    for(int i=0;i<=count-1;i++){
        for()
    }
   

}
