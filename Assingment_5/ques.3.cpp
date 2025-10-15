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
    int i=1;
    while(i<pos-1&&temp1!=NULL){
        temp1=temp1->next;
        i++;
    }
    Node* temp2=temp1->next;
    temp1->next=temp2->next;
    delete temp2;
}

int middle(Node* &head){
  if (!head) {
        cout << "List is empty\n";
        return -1;
    }
    Node* slow = head;
    Node* fast = head;

    while (fast!=NULL && fast->next!=NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow->data;
 }
int main(){
    Node* node1=new Node(4);
    Node* head=node1;
    Node* tail=node1;
    print(head);
    insertathead(head,5);
    print(head);
    insertattail(tail,3);
    print(head);
    insertattail(tail,2);
    print(head);
    insertatpositions(head,6,3);
    print(head);
    cout<<middle(head);
}