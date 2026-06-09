#include <bits/stdc++.h>
using namespace std;
#define vll vector<long long>

int main(){
    int n, q;
    cin>>n>>q;
    vll arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    vll ps(n);
    ps[0] = arr[0];
    for(int i=1;i<n;i++) ps[i] = ps[i-1]+arr[i];

    for(int i=0;i<q;i++){
        int l,r;
        cin>>l>>r;
        l--, r--;
        if(l==0) cout<<ps[r]<<'\n';
        else cout<<ps[r]-ps[l-1]<<'\n';
    }
}