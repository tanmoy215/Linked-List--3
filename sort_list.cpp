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
Node* Marge(Node* list1,Node* list2){
     Node* tempa = list1;
     Node* tempb = list2;
     Node* c = new Node(-1);
     Node* tempc = c;
     while(tempa!=NULL && tempb!=NULL){
         if(tempa->data <= tempb->data){
            tempc->next = tempa;
            tempa = tempa->next;
            tempc = tempc->next;
         }
         else{
            tempc->next = tempb;
            tempb = tempb->next;
            tempc = tempc->next;
         }
     }
     if(tempa==NULL){
        tempc->next = tempb;
     }
     if(tempb==NULL){
        tempc->next = tempa;
     }
    return c->next;
}
Node* sortList(Node* head){
    //base case
    if(head==NULL || head->next==NULL) return head;
     Node* slow = head;
     Node* fast = head;
     //left middle
     while(fast->next!=NULL && fast->next->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
     }
     Node* a = head;
     Node* b = slow->next;
     slow->next = NULL;
     //recursion
     a = sortList(a);
     b = sortList(b);
     Node* c = Marge(a,b);
     return c;
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
  head =  sortList(head);
   display(head);
    return 0;
}