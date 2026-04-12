#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9;
#define F first
#define S second

int n,m;
vector<vector<pair<int,int>>> nbors;
vector<int> visited,distance_from_source;

void dijkstra(int sc){
    distance_from_source.assign(n+1,INF); visited.assign(n+1,0);
    //DS
    priority_queue<pair<int,int>> pq;
    //Setup source;
    distance_from_source[sc]=0;
    pq.push({-0,sc});

    //keep exploring till empty
    while(!pq.empty()){
        auto temp = pq.top(); pq.pop();
        int cur = temp.S;
        if(visited[cur])continue;
        
        //explore
        visited[cur]=1;
        for(auto v: nbors[cur]){
            if(!visited[v.S] && distance_from_source[v.S] > distance_from_source[cur] + v.F){
                distance_from_source[v.S] = distance_from_source[cur] + v.F;
                pq.push(make_pair(-distance_from_source[v.S],v.S));
            }
            
        }
    }
}

void solve(){
    cin >> n >> m;
    nbors.resize(n+1); 
    for(int i=0; i<m; i++){
        int x,y,w;
        cin >> x >> y >> w;
        nbors[x].push_back(make_pair(w,y));
        nbors[y].push_back(make_pair(w,x));
    }
    dijkstra(1);
    for(int i=1; i<=n; i++)cout << distance_from_source[i] << " ";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
}