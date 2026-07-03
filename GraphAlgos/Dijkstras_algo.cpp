#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int V,vector<vector<pair<int,int>>> &adj,int s){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<int> dis(V,INT_MAX);
    vector<bool> processed(V,false);
    dis[s]=0;
    pq.push({0,s});
    while(!pq.empty()){
        int d=pq.top().first;
        int node=pq.top().second;
        pq.pop();

        if(processed[node])continue;
        processed[node]=true;

        for(auto it: adj[node]){
            int edgeWeight=it.second;
            int adjNode=it.first;

            if(d + edgeWeight < dis[adjNode]){
                dis[adjNode]=d + edgeWeight;
                pq.push({dis[adjNode],adjNode});
            }
        }
    }
    return dis;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n=6;
    vector<vector<pair<int,int>>> adj(n);
    adj[0]={{1,4},{2,4}};
    adj[1]={{0,4},{2,2}};
    adj[2]={{0,4},{1,2},{3,3},{5,6},{4,1}};
    adj[3]={{2,3},{5,2}};
    adj[4]={{2,1},{5,3}};
    adj[5]={{3,2},{2,6},{4,3}};
    
    vector<int> dis=dijkstra(n,adj,0);

    for(int i=0;i<n;i++) cout<<dis[i]<<" ";
    cout<<endl;
    return 0;
}