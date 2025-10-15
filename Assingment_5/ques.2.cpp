#include<iostream>
using namespace std;
class Node{
    public :
    int data;
    Node* next;
    Node(int d){
        this->data=d;
        this->next=NULL;  
    }

};
void print(Node* &head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

void insertathead(Node* &head,int d){
     Node* temp=new Node(d);
     temp->next=head;
     head=temp;

}
void insertattail(Node* &tail,int d){
    Node* temp=new Node(d);
    tail->next=temp;
    tail=temp;
}
void insertatpositions(Node* &head,int d,int pos){
    if(pos==1){
        insertathead(head,d);
        return;
    }
    Node* temp=head;
    int i=1;
    while(i<pos-1&&temp!=NULL){
        temp=temp->next;
        i++;
    }
    Node* newnode=new Node(d);
    newnode->next=temp->next;
    temp->next=newnode;
}

void Delete(Node* &head,int pos){
    Node* temp1=head;
    if(pos==1){
        head=head->next;
        temp1->next=NULL;
        delete temp1;
        return;
    }
    int i=1;
    while(i<pos-1&&temp1!=NULL){
        temp1=temp1->next;
        i++;
    }
    Node* temp2=temp1->next;
    temp1->next=temp2->next;
    delete temp2;
}

void key(int ele,Node* &head){
    int count=0;
     Node* temp=head;
     int pos=1;
     while(temp!=NULL){
        if(temp->data==ele){
        temp=temp->next;
        Delete(head,pos);
        count++;
        }
        else{ pos++;
            temp=temp->next;}
     }
     cout<<"number of occurences are : "<<count<<endl;

}
int main(){
    Node* node1=new Node(4);
    Node* head=node1;
    Node* tail=node1;
    insertathead(head,5);
    insertathead(head,3);
    insertathead(head,4);
    insertathead(head,3);
   
    insertathead(head,3);
    
    insertathead(head,2);
    insertattail(tail,3);
    Delete(head,1);
    print(head); 

    key(3,head);
    print(head);
}
