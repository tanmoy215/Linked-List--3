#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
     int data;
     Node* next;
     Node(int data){
         this->data = data;
         this->next = nullptr;
     }
};
void display(Node* head){
    Node* temp = head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
Node* marge(Node* heada, Node* headb){
     Node* a = heada;
     Node* b = headb;
     Node* fake = new Node(-11);
     Node* temp = fake;
     while(a!=nullptr && b!=nullptr){
         if(a->data<=b->data){
            temp->next = a;
            temp = temp->next;
            a = a->next;
         }
         else{
            temp->next = b;
            temp = temp->next;
            b= b->next;
         }
     }
     if(a==nullptr){
        temp->next = b;
     }
     if(b==nullptr){
        temp->next = a;
     }
     return fake->next;
}
int main(){
  Node* heada = new Node(1);
   Node* a = new Node(3);
    Node* b = new Node(5);
     Node* c = new Node(7);
      Node* d = new Node(9);
      //connection
    heada->next = a;
    a->next = b;
    b->next = c;
    c->next = d;

 display(heada);
      Node* headb = new Node(2);
      Node* aa = new Node(4);
      Node* bb = new Node(6);
      Node* cc = new Node(8);
      Node* dd = new Node(10);
      Node* ee = new Node(12);
      Node* ff = new Node(14);
      Node* gg = new Node(16);
      Node* hh = new Node(20);
      //connection
          headb->next = aa;
          aa->next = bb;
          bb->next = cc;
    cc->next = dd;
    dd->next = ff;
    ff->next = gg;
    gg->next = hh;
    display(headb);
    heada = marge(heada,headb);
    display(heada);
    return 0;
}