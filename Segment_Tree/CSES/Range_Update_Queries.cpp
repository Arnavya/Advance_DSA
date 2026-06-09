#include<bits/stdc++.h>
using namespace std;

#define vll vector<long long>

vll A;
vll ST;
vll lazy;

void build(int node, int l, int r){
    if(l==r){
        ST[node] = A[l];
        lazy[node] = 0;
        return;
    }

    int mid = l+(r-l)/2;

    build(2*node+1,l,mid);
    build(2*node+2,mid+1,r);

    ST[node] = ST[2*node+1]+ST[2*node+2];
    lazy[node] = 0;
}

void update(int node, int l , int r, int ql, int qr, int x){
    if(lazy[node]>0){
        ST[node] += lazy[node];
        if(l!=r){
            lazy[2*node+1] += lazy[node];
            lazy[2*node+2] += lazy[node];
        }
        lazy[node] = 0;
    }

    if(qr<l || ql>r) return;
    if(ql<=l && qr>=r){
        ST[node]+=((r-l+1)*x);
        if(l!=r){
            lazy[2*node+1] += x;
            lazy[2*node+2] += x;
        }
        return;
    }
    int mid = l+(r-l)/2;

    update(2*node+1,l,mid,ql,qr,x);
    update(2*node+2,mid+1,r,ql,qr,x);

    ST[node] = ST[2*node+1]+ST[2*node+2];
}

long long query(int node, int l, int r, int ql, int qr){
    if(lazy[node]>0){
        ST[node] += lazy[node];
        if(l!=r){
            lazy[2*node+1] += lazy[node];
            lazy[2*node+2] += lazy[node];
        }
        lazy[node] = 0;
    }

    if(qr<l || ql>r) return 0;
    if(ql<=l && qr>=r) return ST[node];

    int mid = l+(r-l)/2;

    long long left = query(2*node+1,l,mid,ql,qr);
    long long right = query(2*node+2,mid+1,r,ql,qr);

    return left+right;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q;
    cin>>n>>q;
    A.resize(n);
    for(int i=0;i<n;i++) cin>>A[i];
    ST.resize(4*n);
    lazy.resize(4*n);
    build(0,0,n-1);

    for(int i=0;i<q;i++){
        int type;
        cin>>type;
        if(type==1){
            int l,r,x;
            cin>>l>>r>>x;
            l--,r--;
            update(0,0,n-1,l,r,x);
        }
        else{
            int idx;
            cin>>idx;
            idx--;
            cout<<query(0,0,n-1,idx,idx)<<'\n';
        }
    }
}