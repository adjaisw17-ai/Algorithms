#include <bits/stdc++.h>
using namespace std;

void dfs(int node,vector<int>& vis,stack<int>& st,vector<vector<int>>& adj){
    vis[node]=1;
    for(auto it: adj[node]){
        if(!vis[it])
        dfs(it,vis,st,adj);
    }
    st.push(node);
}

vector<int> topoSort(int V,vector<vector<int>>& adj){
    vector<int> vis(V,0);
    stack<int> st;
    for(int i=0;i<V;i++){
        if(!vis[i]){
            dfs(i,vis,st,adj);
        }
    }   
    vector<int> ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    } 
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<vector<int>> adj={{},{},{3},{1},{0,1},{2,0}};
    vector<int> ans=topoSort(6,adj);
    for(auto x:ans) cout<<x<<" ";
    cout<<endl;
    return 0;
}