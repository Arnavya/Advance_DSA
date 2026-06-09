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

    ST[node] = min(ST[2*node+1],ST[2*node+2]);
}

void update(int node, int l, int r, int idx, int val){
    if(l==r){
        A[idx] = val;
        ST[node] = val;
        return;
    }

    int mid = l+(r-l)/2;

    if(idx<=mid) update(2*node+1,l,mid,idx,val);
    else update(2*node+2,mid+1,r,idx,val);

    ST[node] = min(ST[2*node+1],ST[2*node+2]);
}

long long query(int node, int l , int r, int ql, int qr){
    if(qr<l || ql>r) return LLONG_MAX;
    if(ql<=l && qr>=r) return ST[node];
    
    int mid = l+(r-l)/2;

    long long left = query(2*node+1,l,mid,ql,qr);
    long long right = query(2*node+2,mid+1,r,ql,qr);

    return min(left,right);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q;
    cin>>n>>q;
    A.resize(n);
    for(int i=0;i<n;i++) cin>>A[i];
    
    ST.assign(4*n,LLONG_MAX);
    build(0,0,n-1);

    for(int i=0;i<q;i++){
        int a,b,c;
        cin>>a>>b>>c;
        if(a==1) update(0,0,n-1,b-1,c);
        else{
            cout<<query(0,0,n-1,b-1,c-1)<<'\n';
        }
    }
}