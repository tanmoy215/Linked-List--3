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
//using slow and fast pointer
Node* rotate(Node* head,int k){
    if(head==NULL || head->next==NULL) return head;
    Node* slow = head;
    Node* fast = head;
    int n = 0;
    while(slow!=NULL){
        slow = slow->next;
        n++;
    }
    slow = head;
    k = k%n;
    if(k==0) return head;
    for(int i=1;i<=k;i++){
        fast=fast->next;
    }
    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next;
        slow = slow->next;
    }
    fast->next=head;
    head = slow->next;
    slow->next = NULL;
    return head;
}

//1st method 
Node* Rotate(Node* head, int k){
    if(head==NULL || head->next==NULL) return head;
    Node* temp = head;
    Node* tail = NULL;
    int n = 0;
    while(temp!=NULL){
        if(temp->next==NULL) tail=temp;
        temp = temp->next;
        n++;
    }
    k = k%n;
    if(k==0) return head;
    temp = head;
    for(int i=1;i<(n-k);i++){
        temp = temp->next;
    }
    tail->next = head;
    head = temp->next;
    temp->next = NULL;
    return head;
}
 main(){
     Node* head = new Node(10);
    Node* a = new Node(20);
    Node* b = new Node(30);
    Node* c = new Node(40);
    Node* tail = new Node(50);
    head->next = a;
    a->next = b;
    b->next = c;
    c->next = tail;
    display(head);
    int k;
    cout<<"enter k : ";
    cin>>k;
    head = rotate(head,k);
    display(head);
    return 0;
}