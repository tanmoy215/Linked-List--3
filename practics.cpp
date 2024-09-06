#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<vector <int> > arr{{1,2,3},{4,5,6},{7,8,9}};
    int row = arr.size();
    int col = arr[0].size();
    int n = row*col;
    vector<int> ans(n,1);
    
    // for(int i : ans){
    //     cout<<i<<" ";
    // }
    // cout<<endl<<n<<endl;
    return 0;
}