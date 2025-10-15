#include<iostream>
using namespace std;
void binary(queue<int>&q){
    for(int i=1;i<=q.size();i++){
        int front = q.front();
        while(front!=0){
            int ld=0;
            if(front%2==0){
                ld=(ld*10)+0;
                front=front/2;
            }
            else{
                ld=(ld*10)+1;
                front=(front-1)/2;
            }
        }

    }
}
int main(){
    int n;
    cout<<"enter the number : ";
    cin>>n;
    queue<int>q;
    for(int i=1;i<=n;i++){
        q.push(i);
    }
}