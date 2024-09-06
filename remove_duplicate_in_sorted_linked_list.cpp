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
Node* removeduplicate(Node* head){
    if(head==NULL || head->next==NULL) return head;
    Node* a=head;
    Node* b=head->next;
    while(b!=NULL){
        if(a->data == b->data){
            b=b->next;
        }
        else{
            a->next = b;
            a=a->next;
            b=b->next;
        }
    }
    a->next = NULL;
    return head;
}
int main(){
     Node* head = new Node(10);
    Node* a = new Node(10);
    Node* b = new Node(10);
    Node* c = new Node(30);
    Node* tail = new Node(30);
    head->next = a;
    a->next = b;
    b->next = c;
    c->next = tail;
    display(head);
    head = removeduplicate(head);
    display(head);
    return 0;
}