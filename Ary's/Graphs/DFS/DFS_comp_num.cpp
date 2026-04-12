//Count number of students that will get a gossip if the gossip is shared with an Xth student.

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> nbors;
vector<int> comp_no, visited, comp_size;
int n,m,cur_comp_no;

void dfs(int x, int cc){
    visited[x]++;
    comp_no[x] = cc;
    for(auto v: nbors[x]){
        if(!visited[v]){
            dfs(v,cc);
        }
    }
}

void solve(){
    cin >> n >> m;
    nbors.resize(n+1); visited.resize(n+1); comp_no.resize(n+1);
    for(int i=0; i<m; i++){
        int x,y;
        cin >> x >> y;
        nbors[x].push_back(y);
        nbors[y].push_back(x);
    }
    cur_comp_no = 0;
    for(int i=1; i<=n; i++){
        if(!visited[i]){
            cur_comp_no++;
            dfs(i, cur_comp_no);
        }
    }
    // for(int i=1; i<=n; i++){
    //     cout << "Component number of node " << i << " is " << comp_no[i] << endl;
    // }
    comp_size.resize(cur_comp_no+1,0);
    for(int i=1; i<=n; i++){
        comp_size[comp_no[i]]++;
    }
    for(int i=1; i<=cur_comp_no; i++) cout << comp_size[i] << " ";
    
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
}