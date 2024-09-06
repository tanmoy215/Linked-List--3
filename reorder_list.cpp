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
Node* reorder(Node* head){
    Node* slow = head;
    Node* fast = head;
     while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
     } 
     slow = reverse(slow);
    Node* farzi = new Node(-1);
    Node* temp =farzi;
    Node* a = head;
    Node* b = slow;
    while(a!=NULL && b!=NULL){
        temp->next = a;
        temp=temp->next;
        a=a->next;
        temp->next = b;
        b=b->next;
        temp=temp->next;
    }
    temp->next = b;
    return head;
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
   d->next =tail;
   display(head);
   head = reorder(head);
  display(head);
    return 0;
}