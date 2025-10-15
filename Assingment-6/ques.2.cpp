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
void print(Node* &tail) {
    if (tail == NULL) {
        cout << "List is empty\n";
        return;
    }

    Node* temp = tail->next; 
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != tail->next);
    cout<<tail->next->data;
    cout << endl;
}
void insert(Node* &tail,int d,int pos){
    Node* newnode=new Node(d);
   if(tail==NULL){
    tail=newnode;
    newnode->next=newnode;
    return;
   }
   Node* temp=tail->next;
   if(pos==1){
    newnode->next=temp;
    tail->next=newnode;
    return;
   }
   int i=1;
   while(i<pos-1&&temp!=tail){
    temp=temp->next;
    i++;
   }
   newnode->next=temp->next;
   temp->next=newnode;
   if(temp==tail){
    tail=newnode;
   }
}
void deletion(Node* &tail,int pos){
    Node* temp=tail->next;
    int i=1;
    if(pos==1){
        tail->next=temp->next;
        delete temp;
        return;
    }
    while(i<pos-1&&temp!=tail){
        temp=temp->next;
        i++;
    }
    Node* nodetodelete= temp->next;
    temp->next=nodetodelete->next;
    if(nodetodelete==tail){
        tail=temp;
    }
    delete nodetodelete;

}
int main(){
  Node* node1=new Node(5);
  Node* tail=node1;
  tail->next=tail;
  insert(tail,4,1);
   insert(tail,6,2);
   insert(tail,7,2);
   insert(tail,8,4);
  deletion(tail,3);
   print(tail);

}