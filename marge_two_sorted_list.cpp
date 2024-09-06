#include<bits/stdc++.h>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};
void display(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}   
//Space Complexity = O(1)
void Marge(Node* list1,Node* list2){
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
     display(c->next);
}
 //space complexity = O(n+m)
void marge(Node* list1,Node* list2){
    Node* tempa = list1;
    Node* tempb = list2;
    Node* c = new Node(-1);
    Node* tempc = c;
    while(tempa!=NULL && tempb!=NULL){
         if(tempa->data <= tempb->data){
            Node* t = new Node(tempa->data);
            tempc->next = t;
            tempc = t;
            tempa=tempa->next;
         }
         else{
            Node* t = new Node(tempb->data);
            tempc->next = t;
            tempc = t;
            tempb=tempb->next;
         }
    }
    if(tempa==NULL){
        tempc->next = tempb;
    }
    if(tempb==NULL){
        tempc->next = tempb;
    }
    display(c->next);
}
 main(){
    //list 1
     Node* headA = new Node(10);
    Node* a = new Node(20);
    Node* b = new Node(30);
    Node* c = new Node(40);
    Node* tail = new Node(50);
    headA->next = a;
    a->next = b;
    b->next = c;
    c->next = tail;
    //list-2
    Node* headB = new Node(10);
    Node* aa = new Node(20);
    Node* bb = new Node(30);
    Node* cc = new Node(40);
    Node* taill = new Node(50);
    headB->next = aa;
    aa->next = bb;
    bb->next = cc;
    cc->next = taill;
    Marge(headA,headB);
    return 0;
}