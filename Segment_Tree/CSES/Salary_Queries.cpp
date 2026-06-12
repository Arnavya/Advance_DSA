#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef tree<
    pair<int,int>,
    null_type,
    less<pair<int,int>>,
    rb_tree_tag,
    tree_order_statistics_node_update
> ordered_set;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,q;
    cin>>n>>q;
    ordered_set os;
    vector<int> A(n);
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        A[i] = num;
        os.insert({num,i});
    }
    for(int i=0;i<q;i++){
        char sign;
        cin>>sign;
        if(sign=='!'){
            int k,x;
            cin>>k>>x;
            k--;
            os.erase({A[k],k});
            A[k] = x;
            os.insert({x,k});
        }
        else{
            int a,b;
            cin>>a>>b;
            cout<<os.order_of_key({b,INT_MAX})-os.order_of_key({a,INT_MIN})<<'\n';
        }
    }
}