#include<bits/stdc++.h>
using namespace std;

#define vc vector<char>
#define vvc vector<vector<char>>
#define vi vector<int>
#define vvi vector<vector<int>>

void build(vvc& grid, vvi& ps){
    int r = ps.size();
    int c = ps[0].size();

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            int up = 0, left = 0, diag = 0;
            if(i-1>=0) up = ps[i-1][j];
            if(j-1>=0) left = ps[i][j-1];
            if(i-1>=0 && j-1>=0) diag = ps[i-1][j-1];
            if(grid[i][j]=='.') ps[i][j] = 0;
            else ps[i][j] = 1;
            ps[i][j] += up+left-diag;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,q;
    cin>>n>>q;

    vvc grid(n,vc(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
        }
    }

    vvi ps(n,vi(n));

    build(grid,ps);

    for(int i=0;i<q;i++){
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        x1--,y1--,x2--,y2--;

        int left = 0, right = 0, diag = 0;
        int ans = ps[x2][y2];
        if(x1-1>=0) ans-=ps[x1-1][y2];
        if(y1-1>=0) ans-=ps[x2][y1-1];
        if(x1-1>=0 && y1-1>=0) ans+=ps[x1-1][y1-1];
        cout<<ans<<'\n';
    }

}