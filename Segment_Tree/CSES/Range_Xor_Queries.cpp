#include<bits/stdc++.h>
using namespace std;
#define vll vector<long long>

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q;
    cin>>n>>q;
    vll A(n);
    cin>>A[0];
    for(int i=1;i<n;i++){
        cin>>A[i];
        A[i] = A[i]^A[i-1];
    }

    for(int i=0;i<q;i++){
        int a,b;
        cin>>a>>b;
        a--,b--;
        if(a==0) cout<<A[b]<<'\n';
        else cout<<(A[b]^A[a-1])<<'\n';
    }

}