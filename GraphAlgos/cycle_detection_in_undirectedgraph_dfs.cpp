#include <bits/stdc++.h>

using namespace std;

bool detect_cycle_dfs(int src, vector<vector<int>>& adj, vector<bool> &visited, int parent){
    visited[src]=true;
    for(auto adjnode:adj[src]){
        if(!visited[adjnode]){
            if(detect_cycle_dfs(adjnode,adj,visited,src)){
                return true;
            }
        }
        else if(parent!=adjnode){
            return true;
        }
    }
    return false;
}

void solve(){
    vector<vector<int>> adj(11);
    adj[1]={2,5};
    adj[2]={1,3};
    adj[3]={2,4};
    adj[4]={3,9};
    adj[5]={1,6,10};
    adj[6]={5,6};
    adj[7]={6,8};
    adj[8]={7,9};
    adj[9]={4,8};
    adj[10]={5};
    vector<bool> visited(11,false);
    for(int i=1;i<=10;i++){
        if(!visited[i]){
            if(detect_cycle_dfs(i,adj,visited,-1)){
                cout<<"Cycle Detected\n";
                return;
            }
        }
    }
    cout<<"No Cycle Detected\n";

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    
    return 0;
}