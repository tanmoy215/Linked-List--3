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
Node* reverse(Node* head){
  Node *curr = head,*prev = NULL,*Next = NULL;
    // Node* curr = head;
    // Node* prev = NULL;
    // Node* Next = NULL;
    while(curr!=NULL){
        Next = curr->next;
        curr->next = prev;
        prev=curr;
        curr = Next;
    }
    return prev;
}
Node* reverseII(Node* head, int left, int right){
    if(left==right) return head;
    Node* a = NULL;
    Node* b = NULL;
    Node* c = NULL;
    Node* d = NULL;
    Node* temp = head;
    int n = 1;
    while(temp!=NULL){
        if(n==left-1) a=temp;
        if(n==left) b=temp;
        if(n==right) c=temp;
        if(n==right+1) d=temp;
        n++;
        temp = temp->next;
    }
    if(a!=NULL) a->next = NULL;
    c->next = NULL;
    c=reverse(b);
    if(a) a->next = c;
    b->next = d;
    if(a) return head;
    return c;
}
int main(){
     Node* head = new Node(10);
   Node* a = new Node(50);
   Node* b = new Node(30);
   Node* c = new Node(20);
   Node* d = new Node(90);
   Node* e = new Node(80);
   Node* tail = new Node(70);
   head->next = a;
   a->next = b;
   b->next = c;
   c->next = d;
   d->next = e;
   e->next = tail;
   display(head);
  head =  reverseII(head,3,5);
  display(head);
    return 0;
}