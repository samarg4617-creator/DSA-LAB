#include<iostream>
using namespace std;
class Node{
      public:
    int data;
     Node* next;
     public:
     Node(int n){
        data=n;
        this->next=NULL;  
     }
     };
     void insertatend(Node* &head,Node* &tail,int m){
        if(tail==NULL){
            Node* newnode=new Node(m);
            tail=newnode;
            head=tail;
        }
        Node* newnode=new Node(m);
        newnode->next=tail->next;
        tail->next=newnode;
        tail=newnode;

     }
     void print(Node* &head,Node* &tail){
        if(head==NULL){
         cout<<"nothing present";
        }
        Node* temp=head;
        do{
            cout<<temp->data;
            temp=temp->next;
        }while(temp!=tail->next);
     }

     void split(Node* &head,Node* &tail){
        Node* slow=head;
        Node* fast=head;
        while(fast->next!=tail->next &&fast->next->next!=tail->next){
            slow=slow->next;
            fast=fast->next->next;}

        Node* temp1=head;
        Node* temp2=slow->next;
        cout<<"the first linklist is : ";
        while(temp1!=temp2){
            cout<<temp1->data<<" ";
            temp1=temp1->next;
        }
        cout<<endl;
        cout<<"the second linklist is : ";
        while(temp2!=tail->next){
            cout<<temp2->data<<" ";
            temp2=temp2->next;
        }
     }

int main(){
Node* newnode=new Node(4);
Node* head=newnode;
Node* tail=newnode;
insertatend(head,tail,5);
print(head,tail);
insertatend(head,tail,6);

split(head,tail);
}