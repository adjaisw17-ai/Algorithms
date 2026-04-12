#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<vector<int>> nbors;
vector<int> visited;

bool dfs(int node, int parent){
    visited[node]=1;
    
    for(auto v : nbors[node]){
        if(!visited[v]){
            if(dfs(v,node))return true;
        }
        else if(v!=parent){
            return true;
        }
    }
    return false;
}

void solve(){
    cin >> n >> m;
    visited.resize(n+1); nbors.resize(n+1);
    for(int i=0; i<m; i++){
        int x,y;
        cin >> x >> y;
        nbors[x].push_back(y);
        nbors[y].push_back(x);
    }
    cout << dfs(1,-1) << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
}

//https://codeforces.com/problemset/problem/510/B try this for cycle detection problem.
