#include<bits/stdc++.h>
using namespace std;
#define vll vector<long long>

vll A;
vll ST;

void build(int node, int l, int r){// idx of ST ,  [l,r] -> range that node represents in array A.
    if(l==r){
        ST[node] = A[l];
        return;
    }
    int mid = l+(r-l)/2;
    build(2*node+1,l,mid);
    build(2*node+2,mid+1,r);

    ST[node] = min(ST[2*node+1],ST[2*node+2]);
}

long long query(int node, int l, int r, int ql, int qr){
    
    if(qr<l || ql> r) return LLONG_MAX;
    if(ql<=l && qr>=r) return ST[node];

    int mid = l+(r-l)/2;

    long long left = query(2*node+1, l, mid, ql, qr);
    long long right = query(2*node+2, mid+1, r, ql, qr);

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
        int l, r;
        cin>>l>>r;
        l--, r--;
        cout<<query(0,0,n-1,l,r)<<'\n';
    }
}