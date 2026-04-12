//Important and all possible applicationsof DFS :-
// 1. Reachability
// 2. Component numbering
// 3. Bi-Partite
// 4. Cycle finding
// 5. Topological ordering

//Count number of students that will get a gossip if the gossip is shared with an Xth student.
#include<bits/stdc++.h>
using namespace std;

int n,m,cnt;
vector<vector<int>> neighbors;
vector<int> visited;

void dfs(int x){
    visited[x]=1;
    for(auto v:neighbors[x]){
        if(!visited[v]){
            dfs(v);
        }
    }
}

void solve(){
    cin >> n >> m;
    neighbors.resize(n+1); visited.resize(n+1);
    for(int i=0; i<m; i++){
        int x,y;
        cin >> x >> y;
        neighbors[x].push_back(y);
        neighbors[y].push_back(x);
    }
    for(auto v: neighbors){
        for(int i=0; i<v.size(); i++){
            cout << v[i] << " ";
        }
        cout << endl;
    }
    for(int i=1; i<=n; i++){
        dfs(i);
        cnt=0;
        for(int j=1; j<=n; j++){
            if(visited[j]==1)cnt++;
        }
        cout << cnt << endl;
        cnt=0;
        fill(visited.begin(),visited.end(),0);
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
}

// #include<bits/stdc++.h>
// using namespace std;

// int n,m;
// vector<vector<int>> nbors;
// vector<int> visited;

// void dfs(int x){
//     visited[x]=1;
//     for(auto v: nbors[x]){
//         if(!visited[v]){
//             dfs(v);
//         }
//     }
// }

// void solve(){
//     cin >> n >> m;
//     nbors.resize(n+1); visited.resize(n+1);
//     for(int i=0; i<m; i++){
//         int x,y;
//         cin >> x >> y;
//         nbors[x].push_back(y);
//         nbors[y].push_back(x);
//     }
//     dfs(1);
//     for(auto v: visited)cout << v << " ";
// }

// signed main() {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0); cout.tie(0);
//     solve();
// }