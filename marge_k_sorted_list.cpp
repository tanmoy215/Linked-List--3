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
Node* Merge(Node* list1,Node* list2){
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
Node* margelist(vector<Node*> arr){
       if(arr.size()==0) return NULL;
       while(arr.size()>1){
        Node* a = arr[0];
        arr.erase(arr.begin());
        Node* b = arr[0];
        arr.erase(arr.begin());
        Node* c = Merge(a,b);
        arr.push_back(c);
       }
       return arr[0];
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
    Node* headB = new Node(60);
    Node* aa = new Node(70);
    Node* bb = new Node(80);
    Node* cc = new Node(90);
    Node* taill = new Node(100);
    headB->next = aa;
    aa->next = bb;
    bb->next = cc;
    cc->next = taill;
    //list - 3
    Node* headC = new Node(110);
    Node* aaa = new Node(120);
    Node* bbb = new Node(130);
    Node* ccc = new Node(140);
    Node* tailll = new Node(150);
    headC->next = aaa;
    aaa->next = bbb;
    bbb->next = ccc;
    ccc->next = tailll;
    vector<Node*> ans{headA,headB,headC};
     Node* head = margelist(ans);
     display(head);
    return 0;
}