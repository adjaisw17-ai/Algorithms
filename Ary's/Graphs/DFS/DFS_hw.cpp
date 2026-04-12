//given a graph, how many (x,y)unordered pairs exist which are not resen in the graph
// now, but if added then the number of components will decrease? Count such number of 
//(x,y) unordered pairs.
//Constraints are N,M <= 10^5;

#include<bits/stdc++.h>
using namespace std;

#define int long long

int n,m,cur_comp_no;
vector<vector<int>> nbors;
vector<int> visited,comp_no;

void dfs(int node, int cc){
    visited[node] = 1;
    comp_no[node] = cc;
    for(auto v: nbors[node]){
        if(!visited[v]){
            dfs(v,cc);
        }
    }
}

void solve(){
    cin >> n >> m;
    visited.resize(n+1); nbors.resize(n+1); comp_no.resize(n+1);
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
            dfs(i,cur_comp_no);
        }
    }
    vector<int> comp_size(cur_comp_no+1,0);
    for(int i=1; i<=n; i++){
        comp_size[comp_no[i]]++;
    }

    //T.C of below code is O(n^2). Constraints suggest N,M <= 10^5;
    // int total_pairs = 0;
    // for(int i=1; i<=cur_comp_no; i++){
    //     for(int j=i+1; j<=cur_comp_no; j++){
    //         total_pairs += comp_size[i]*comp_size[j];
    //     }
    // }

    //O(N) Using prefix sum;
    int sum=0,total=0;
    for(int i=1; i<=cur_comp_no; i++){
        total+=sum*comp_size[i];
        sum+=comp_size[i];
    }
    cout << total << endl;

    //O(N) Using mathematical formula;
    // int sum1=0, sum2=0;
    // for(int i=1; i<=cur_comp_no; i++){
    //     sum1+=comp_size[i];
    //     sum2+= comp_size[i]*comp_size[i];
    // }
    // cout << (sum1*sum1 - sum2)/2 << endl;


}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
}