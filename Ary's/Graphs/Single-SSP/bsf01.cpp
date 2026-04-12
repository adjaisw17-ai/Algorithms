#include<bits/stdc++.h>
using namespace std;

//MARKING A NODE VISITED MEANS FINALIZING ITS DISTANCE;

#define F first
#define S second
const int INF =1e9;

int n,m;
vector<vector<pair<int,int>>> nbors;
vector<int> visited,dist;

void bfs01(int sc){
    visited.assign(n+1,0); dist.assign(n+1,INF);

    //setup a dequeue;
    deque<int> node_dq;
    
    //setup source
    dist[sc] = 0;
    //visited[sc] = 1;  NOTE: YE YAHAN NAHI LIKHNA HAI. A node will only be marked visited when it comes out of dequeue or queue.
    node_dq.push_front(sc);
    
    //now keep exploring till empty;
    while(!node_dq.empty()){
        int cur = node_dq.front();
        node_dq.pop_front();
        
        if(visited[cur])continue;

        //explore
        visited[cur]=1;
        for(auto v: nbors[cur]){
            if(!visited[v.F] && dist[v.F]>dist[cur]+v.S){
                dist[v.F] = dist[cur]+v.S;
                if(v.S==0){
                    node_dq.push_front(v.F);
                }
                else{
                    node_dq.push_back(v.F);
                }
            }
        }
    }

}

void solve(){
    cin >> n >> m;
    nbors.resize(n+1);
    for(int i=0; i<m; i++){
        int a,b,c;
        cin >> a >> b >> c;
        nbors[a].push_back({b,c});
        nbors[b].push_back({a,c});
    }
    bfs01(1);
    for(int i=1; i<=n; i++){
        cout << "Node " << i << " is at distance " << dist[i] << endl; 
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
}