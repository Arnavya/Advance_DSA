#define vi vector<int>
#define vvi vector<vector<int>>
#define vll vector<long long>
#define vvll vector<vector<long long>>

#include<bits/stdc++.h>
using namespace std;

vi arr;
vi ST;

void build(int node, int L, int R){//idx of ST, [L,R]-> Range it covers
    if(L==R){
        ST[node] = arr[L];
        return;
    }
    int mid = L+(R-L)/2;
    build(2*node+1,L,mid);//Build left tree
    build(2*node+2,mid+1,R);//Build right tree
    ST[node] = min(ST[(2*node)+1],ST[(2*node)+2]);// take min of left node,  right node.
}//Note: All values of original array is present at leaf nodes of ST array.
// SegementTree array represents a complete binary search tree.

void update(int node, int s, int e, int idx, int val){// node -> current node of ST
                                                      // s,e -> represts the range of the actual array that 
                                                      //.       node covers.
    if(s==e){
        //We are at leaft node of Segment Tree
        arr[idx] = val;
        ST[node] = val;
        return;
    }

    int mid = s+(e-s)/2;

    if(idx<=mid) update(2*node+1, s,mid, idx,val);
    else update(2*node+2,mid+1,e,idx,val);

    ST[node] = min(ST[(2*node)+1],ST[(2*node)+2]);
}

int query(int node, int l, int r, int ql, int qr){

    if(ql>r ||qr<l) return INT_MAX;// ql qr l r || l r ql qr
    
    if(ql<=l && qr>=r) return ST[node]; // ql l r qr

    int mid = l+(r-l)/2;

    int left = query(2*node+1, l, mid, ql, qr);
    int right = query(2*node+2, mid+1, r, ql, qr);

    return min(left,right);
}


//Q) You have to find the minumum in the range given and array can be updated.
 //1 -> find the min in the range[L,R]->[1,L,R] // 2-> update the value at idx with val[2, idx, val];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vi arr = {1,2,5,6,4,2,3,1};//{0,7}
    int n = arr.size();
    int size_of_ST = (2*n)-1;
    vi ST(size_of_ST);
    arr = arr;
    ST = ST;

    build(0,0,n-1);//idx of ST, [L,R]->range it convers

    vvi operations = {{1,2,5},
                 {2,4,-1},
                 {1,2,5}};
     
    for(int i=0;i<operations.size();i++){
        if(operations[i][0]==1){
            int ql = operations[i][1];
            int qr = operations[i][2];
            cout<<"MINIMUM in [L, R] -> "+query(0, 0, 7, ql, qr)<<'\n';
        }
        else if(operations[i][0]==2){
            int idx = operations[i][1];
            int val = operations[i][2]; 
            update(0, 0, 7, idx, val);
        }
    }             
}




