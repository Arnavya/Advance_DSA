#include<bits/stdc++.h>
using namespace std;

#define vll vector<long long>

vll A;
vll ST;

void build(int node, int l, int r){
    if(l==r){
        ST[node] = A[l];
        return;
    }
    int mid = l+(r-l)/2;
    build(2*node+1,l,mid);
    build(2*node+2,mid+1,r);
    ST[node] = max(ST[2*node+1],ST[2*node+2]);
}

int query(int node, int l, int r, int rooms){
    if(l==r){
        if(ST[node]<rooms) return 0;
        ST[node] -= rooms;
        A[l] -= rooms;
        return l+1;
    }
    if(ST[node]< rooms) return 0;

    int mid = l+(r-l)/2;

    int leftidx = query(2*node+1, l, mid, rooms);
    int rightidx = 0;
    if(leftidx==0) rightidx = query(2*node+2, mid+1,r,rooms);
    ST[node] = max(ST[2*node+1],ST[2*node+2]);
    return max(leftidx,rightidx);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    A.resize(n);
    ST.assign(4*n,0);
    for(int i=0;i<n;i++) cin>>A[i];

    build(0,0,n-1);

    for(int i=0;i<m;i++){
        int rooms;
        cin>>rooms;
        cout<<query(0,0,n-1,rooms)<<' ';
    }
    cout<<'\n';
}

