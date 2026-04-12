#include <bits/stdc++.h>

using namespace std;

bool detect_cycle_bfs(int src, vector<vector<int>>& adj, vector<bool> &visited){
    queue<pair<int,int>>q;
    visited[src]=true;
    q.push({src,-1});
    while(!q.empty()){
        int node=q.front().first;
        int parent=q.front().second;
        q.pop();
        for(auto adjnode:adj[node]){
            if(!visited[adjnode]){
                visited[adjnode]=true;
                q.push({adjnode,node});
            }
            else if(parent!=adjnode){
                return true;
            }
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
            if(detect_cycle_bfs(i,adj,visited)){
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