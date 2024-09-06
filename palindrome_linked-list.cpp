// #include<bits/stdc++.h>
// using namespace std;
// class Node{
//     public:
//     int data;
//     Node* next;
//     Node(int data){
//         this->data = data;
//         this->next = NULL;
//     }
// };
// void display(Node* head){
//     while(head!=NULL){
//         cout<<head->data<<" ";
//         head = head->next;
//     }
//     cout<<endl;
// }
// Node* GetNodet(Node* head, int idx){
//      Node* temp = head;
//      for(int i=1;i<=idx;i++){
//         temp = temp->next;
//      }
//      return temp;
// }
// bool palindrome(Node* head){
//      Node* temp = head;
//      int len = 0;
//      while(temp!=NULL){
//         len++;
//         temp = temp->next;
//      }                                           Method Number = 1
//      int i = 0;
//      int j=len-1;
//      while(i<j){
//         Node* left = GetNodet(head,i);
//         Node* right = GetNodet(head,j);
//         if(left->data != right->data) return false;
//         i++;
//         j--;
//      }
//      return true;
// }
// Node* GetNodeAt(Node* head, int idx){
//     Node* temp = head;
//     for(int i=0;i<idx;i++){
//         temp = temp->next;
//     }
//     return temp;
// }
// int main(){
//      Node* head = new Node(10);
//    Node* a = new Node(20);
//    Node* b = new Node(30);
//    Node* c = new Node(30);
//    Node* d = new Node(20);
//    Node* tail = new Node(10);
//    head->next = a;
//    a->next = b;
//    b->next = c;
//    c->next = d;
//    d->next = tail;
//    display(head);
//    bool flag = palindrome(head);
//     if(flag) cout<<"Yes, It is Palindrome Linked List"<<endl;
//     else cout<<"No, its Not a Palindrome Linked List"<<endl;
//     return 0;
// }




//method NUmber  = 2
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
bool Palindrome(Node* head){
    Node* temp = head;
    Node* c=new Node(-1);
    Node* tempc = c;
    while(temp!=NULL){
        Node* t = new Node(temp->data);
        tempc->next = t;
        tempc=tempc->next;
        temp=temp->next;
    }
    c = c->next;
    c=reverse(c);
    temp = head;
    while(temp!=NULL){
        if(temp->data != c->data) return false;
        temp= temp->next;
        c=c->next;
    }
    return true;
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
   if(Palindrome(head)) cout<<"Yes"<<endl;
   else cout<<"NO"<<endl;
    return 0;
}