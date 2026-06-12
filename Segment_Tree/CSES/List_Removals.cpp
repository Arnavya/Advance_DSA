#include<bits/stdc++.h>
using namespace std;
#define vll vector<long long>

vll A;
vll ST;

void build(int node, int l, int r){
    if(l==r){
        ST[node] = 1;
        return;
    }
    int mid = l+(r-l)/2;

    build(2*node+1, l, mid);
    build(2*node+2, mid+1, r);

    ST[node] = ST[2*node+1] + ST[2*node+2];
}

int query(int node, int l, int r, int pos){
    if(l==r){
        if(ST[node]==0 || pos!=1) return -1;
        else{
            ST[node] = 0;
            return A[l];
        }
    }
    if(ST[node] < pos) return -1;

    int mid = l+(r-l)/2;

    int left = query(2*node+1, l, mid, pos);
    int right = -1;
    if(left==-1) right = query(2*node+2, mid+1, r, pos-ST[2*node+1]);
    ST[node] = ST[2*node+1] + ST[2*node+2];
    return max(left,right);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    A.resize(n);
    for(int i=0;i<n;i++) cin>>A[i];
    ST.assign(4*n,0);

    build(0,0,n-1);

    for(int i=0;i<n;i++){
        int pos;
        cin>>pos;
        cout<<query(0,0,n-1,pos)<<" ";
    }
    cout<<'\n';
}