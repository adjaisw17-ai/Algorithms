// Ques 2. Given a classroom with N students and M relations. 
// There is too many gossip hence it is decided that this class will now be divided into 2 sections.
// Divide students in such a way that there is no gossip ever.

//BI-PARTITE COLORING
//Can we color all vertices using only 2 colors
//such that no adjacent vertices have the same color?

//A graph is bipartite if and only if:
// It contains no odd-length cycle
// Odd cycle → impossible to 2-color.

// Example:
// 3-cycle (triangle) ❌ not bipartite
// 4-cycle ✅ bipartite

#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<vector<int>> nbors;
vector<int> color_of_node, visited;

bool is_bipartite=true;

void dfs(int node, int color){
    visited[node]=1;
    color_of_node[node] = color;
    for(auto v: nbors[node]){
        if(!visited[v]){
            dfs(v, 1-color);
        }
        else if(color_of_node[v] == color_of_node[node]){
            is_bipartite=false;
        }
    }
}

void solve(){
    cin >> n >> m;
    nbors.resize(n+1); color_of_node.resize(n+1); visited.resize(n+1);
    for(int i=0; i<m; i++){
        int x,y;
        cin >> x >> y;
        nbors[x].push_back(y);
        nbors[y].push_back(x);
    }
    for(int i=1; i<=n; i++){
        if(!visited[i]){
            dfs(i,1);
        }
    }
    if(is_bipartite){
        cout << "YES\n";
        for(int i=1; i<=n; i++){
            cout << "Color of node " << i << " is " << color_of_node[i] << endl;
        }
    }
    else{
        cout << "NO\n";
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
}