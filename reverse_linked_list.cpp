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
    Node* temp = head;
    int len =0;
    while(temp!=NULL){
        len++;
        temp=temp->next;
    }
    int i =0;
    int j = len-1;
    while(i<j){
        Node* left = GetNodeAt(head,i);
        Node* right = GetNodeAt(head,j);
        //swap
        int temp = left->data;
        left->data = right->data;
        right->data = temp;
        i++;
        j--;
    }
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
   d->next = tail;
   display(head);
   head = reverse(head);
   display(head);
    return 0;
}