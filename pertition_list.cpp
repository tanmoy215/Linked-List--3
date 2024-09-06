#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};
void display(Node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}
Node* pertition(Node* head,int x){
    Node* high = new Node(-1);
    Node* low = new Node(-1);
    Node* templow = low;
    Node* temphigh = high;
    Node* temp = head;
    while(temp!=NULL){
        if(temp->data < x){
            templow->next = temp;
            temp=temp->next;
            templow = templow->next;
        }
        else{
            temphigh->next = temp;
            temp = temp->next;
            temphigh= temphigh->next;
        }
    }
    templow->next = high->next;
    temphigh->next = NULL;
    return low->next;
}
int main(){
     Node* head = new Node(10);
   Node* a = new Node(50);
   Node* b = new Node(30);
   Node* c = new Node(20);
   Node* d = new Node(90);
   Node* tail = new Node(70);
   head->next = a;
   a->next = b;
   b->next = c;
   c->next = d;
   d->next = tail;
   head = pertition(head,30);
   display(head);
    return 0;
}