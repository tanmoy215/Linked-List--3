#include<bits/stdc++.h>
using namespace std;
class Node{
public:
 int data;
 Node* next;
 Node(int n){
    data = n;
    next= NULL;
 }
};
vector<vector<int> >spiralMatrix(int row, int col,Node* head){
        vector<vector<int> > arr(row,vector<int> (col,-1));
         int minr = 0;
         int maxr = row-1;
         int minc = 0;
         int maxc = col-1;
         Node* temp = head;
         while(minr<=maxr && minc<=maxc){
             //right
             for(int j=minc;j<=maxc;j++){
                if(temp==NULL) return arr;
                    arr[minr][j]=temp->data;
                    temp = temp->next;
             }
             minr++;
             if(minr>maxr && minc>maxc) break;
             //down
             for(int i=minr;i<=maxr;i++){
                if(temp==NULL) return arr;
                arr[i][maxc]=temp->data;
                temp = temp->next;
             }
             maxc--;
             if(minr>maxr && minc>maxc) break;
             //left
             for(int j=maxc;j>=minc;j--){
                if(temp==NULL) return arr;
                arr[maxr][j]=temp->data;
                temp = temp->next;
             }
             maxr--;
             if(minr>maxr && minc>maxc) break;
             //top
             for(int i=maxr;i>=minr;i++){
                if(temp==NULL) return arr;
                arr[i][minc] = temp->data;
                temp=temp->next;
             }
             minc++;
             if(minr>maxr && minc>maxc) break;
         }
         return arr;
}
int main(){
     Node* head = new Node(10);
    Node* a = new Node(20);
    Node* b = new Node(30);
    Node* c = new Node(40);
    Node* d = new Node(40);
     Node* e = new Node(20);
    Node* f = new Node(30);
    Node* g = new Node(40);
     Node* h = new Node(20);
    Node* i = new Node(30);
    Node* j = new Node(40);
    Node* tail = new Node(50);
    head->next = a;
    a->next = b;
    b->next = c;
    c->next = d;
     d->next = e;     //m = 3, n = 5, head = [3,0,2,6,8,1,7,9,4,2,5,5,0]
     e->next =f;
     f->next =g;
     g->next =h;
     h->next =i;
     i->next=j;
     j->next=tail;
     int col=5;
     int row=3;
     vector<vector<int>> ans = spiralMatrix(row, col, head);
        //output
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                cout<<ans[i][j]<<" ";
            }
            cout<<endl;
        }
    return 0;
}