class Solution {
public:
    const int INF=1e9;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<pair<int,int>>adj[n+1];
        for (auto e:times){
            adj[e[0]].push_back(make_pair(e[1],e[2]));
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>dist(n+1,INF);

        dist[k]=0;
        pq.push(make_pair(0,k));
        while (!pq.empty()){
            int dis=pq.top().first;
            int nodeA=pq.top().second;
            pq.pop();

            for (auto it:adj[nodeA]){
                int nodeB=it.first;
                int w=it.second;

                if (dist[nodeB]>dist[nodeA]+w){
                    dist[nodeB]=dist[nodeA]+w;
                    pq.push(make_pair(dist[nodeB],nodeB));
                }

            }
        }
        int ans=0;
        for (int i=1;i<=n;i++){
            if (dist[i]==INF)return -1;
            ans=max(ans,dist[i]);
        }
        return ans;
    }
};