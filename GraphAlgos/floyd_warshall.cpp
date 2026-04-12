#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9;

void floyd_warshall(){
    int n,m;
    cin >> n >> m;
    int adj[n+1][n+1];
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i==j)adj[i][j]=0;
            else{
                adj[i][j] = INF;}
        }
    }
    for(int i=0; i<m; i++){
        int a,b,w;
        cin >> a >> b >> w;
        //Assuming directed graph
        adj[a][b] = min(adj[a][b],w);
    }
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                adj[i][j] = min(adj[i][k]+adj[k][j],adj[i][j]);
            }
        }
    }
    //adj[i][j] stores shortest path from i to j;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cout << "distance from node " << i << " to node " << j << " = " << adj[i][j] << endl;
        }
    }
}

void solve(){
    floyd_warshall();
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
}