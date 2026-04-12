#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int n,m;

void solve(){
    cin >> n >> m;
    vector<vector<int>> edges;
    for(int i=0; i<m; i++){
        int a,b,w;
        cin >> a >> b >> w;
        edges.push_back({a,b,w});
    }
    vector<int> dist(n+1,INF);
    int changed=0;
    dist[1] = 0;
    for(int i=0; i<n-1; i++){
        for(auto edge : edges){
            if(dist[edge[1]]!=INF && dist[edge[1]] > dist[edge[0]]+edge[2]){
                dist[edge[1]] = dist[edge[0]]+edge[2];
            }
        }
    }
    for(auto edge : edges){
        if(dist[edge[0]]!=INF && dist[edge[1]] > dist[edge[0]]+edge[2]){
            dist[edge[1]] = dist[edge[0]]+edge[2];
            changed=1;
        }
    }
    
    if(changed){
        cout << "Negative cycle detected!";
    }else{
        for(int i=1; i<=n; i++){
            cout << "Distance of node " << i << " from source is " << dist[i] << endl;
        }
    }

}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
}