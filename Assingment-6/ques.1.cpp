// Doubly linklist
// #include<iostream>
// using namespace std;
// class Node{
//     public :
//     int data;
//     Node* next;
//     Node* prev;

//     Node(int d){
//         this->data=d;
//         this->next=NULL;
//         this->prev=NULL;
//     }

// };
// void print(Node* &head){
//     Node* temp=head;
//     while(temp!=NULL){
//         cout<<temp->data<<" ";
//         temp=temp->next;
//     }
//     cout<<endl;

// }
// void insertathead(Node* &head,int d){
//     Node* temp=new Node(d);
//     temp->next=head;
//     head->prev=temp;
//     head=temp;
// }
// void insertattail(Node* &tail,int d){
//     Node* temp=new Node(d);
//     tail->next=temp;
//     temp->prev=tail;
//     tail=temp;

// }
// void insertion(Node* &head,int pos,int d){
    
//     if(pos==1){
//         insertathead(head,d);
//         return;
//     }
//      Node* temp=head;
//      int i=1;
//      while( i<pos-1&&temp!=NULL){
//         temp=temp->next;
//         i++;
//      }
//      Node* temp2=new Node(d);
//      temp2->next=temp->next;
//      temp->next=temp2;
//      temp2->prev=temp;
//      if(temp2->next != NULL){
//     temp2->next->prev = temp2;
// }
// }
// void deletion(Node* &head, int pos) {
//     if (head == NULL) {
//         cout << "List is empty\n";
//         return;
//     }

//     Node* temp = head;

//     if (pos == 1) {
//         head = head->next;
//         if (head != NULL) {
//             head->prev = NULL;
//         }
//         delete temp;
//         return;
//     }


//     int i = 1;
//     while (i < pos && temp != NULL) {
//         temp = temp->next;
//         i++;
//     }

//     if (temp == NULL) {
//         cout << "Position out of bounds\n";
//         return;
//     }

//     if (temp->prev != NULL) {
//         temp->prev->next = temp->next;
//     }

//     if (temp->next != NULL) {
//         temp->next->prev = temp->prev;
//     }

//     delete temp;
// }
// int main(){
//     Node* node1=new Node(5);
//     Node* head=node1;
//     Node* tail=node1;
//     insertathead(head,6);
//     print(head);
//     insertattail(tail,7);
//     print(head);
//     insertion(head,4,4);
//     print(head);
//     deletion(head,2);
//     print(head); 
// }




// Circular linklist
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

    Node* temp = tail->next; // head
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != tail->next);
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
  print(tail);
  insert(tail,4,1);
  print(tail);
   insert(tail,6,2);
  print(tail);
   insert(tail,7,2);
  print(tail);
   insert(tail,8,4);
  print(tail);
  deletion(tail,3);
  print(tail);

}