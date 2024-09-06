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
Node* GetNodeAt(Node* head, int idx){
     Node* temp = head;
     for(int i=1;i<=idx;i++){
        temp = temp->next;
     }
     return temp;
}
Node* reverse(Node* head){
 if(head==NULL || head->next==NULL) return head;
 Node* newNode = reverse(head->next);
  head->next->next = head;
  head->next = NULL;
  return newNode;
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
   display(head);
   head = reverse(head);
   display(head);
    return 0;
}