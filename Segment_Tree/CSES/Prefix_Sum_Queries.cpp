#include<bits/stdc++.h>
using namespace std;

#define vll vector<long long>
#define pll pair<long,long>
#define vpll vector<pll> //prefix, sum

vll A;
vpll ST;

pll merge(pll& left, pll& right){
    pll ans = {max(left.first,left.second+right.first), left.second+right.second};
    return ans;
}
void build(int node, int l, int r){
    if(l==r){
        ST[node] = {max(0LL,A[l]),A[l]};
        return;
    }

    int mid = l+(r-l)/2;

    build(2*node+1, l, mid);
    build(2*node+2, mid+1, r);

    ST[node] = merge(ST[2*node+1],ST[2*node+2]);
}

void update(int node, int l, int r, int idx, long long val){
    if(l==r){
        ST[node] = {max(0LL,val),val};
        return;
    }

    int mid = l+(r-l)/2;

    if(idx<=mid) update(2*node+1, l, mid, idx, val);
    else update(2*node+2, mid+1, r, idx, val);

    ST[node] = merge(ST[2*node+1],ST[2*node+2]);
}

pll query(int node, int l, int r, int ql, int qr){
    if(qr<l || ql>r) return {0,0};
    if(ql<=l && qr>=r) return ST[node];

    int mid = l+(r-l)/2;

    pll left = query(2*node+1, l, mid, ql, qr);
    pll right = query(2*node+2, mid+1, r, ql, qr);

    return merge(left,right);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,q;
    cin>>n>>q;

    A.resize(n);
    for(int i=0;i<n;i++) cin>>A[i];
    ST.resize(4*n);

    build(0,0,n-1);

    for(int i=0;i<q;i++){
        int type, a, b;
        cin>>type>>a>>b;
        if(type==1){
            a--;
            update(0,0,n-1,a,b);
        }
        else{
            a--,b--;
            cout<<query(0,0,n-1,a,b).first<<'\n';
        }
    }
}