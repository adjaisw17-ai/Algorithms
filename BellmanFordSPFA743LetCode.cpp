class Solution {
public:
    const int INF=1e9;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<int>dist(n+1,INF);
        vector<pair<int,int>>adj[n+1];
        for (auto e:times){
            adj[e[0]].push_back(make_pair(e[1],e[2]));
        }
        dist[k]=0;
        queue<int>q;
        vector<bool>inqueue(n+1,false);
        vector<int>cnt(n+1,0);

        q.push(k);
        inqueue[k]=true;
        while (q.size()){
            int nodeA=q.front();
            q.pop();
            inqueue[nodeA]=false;

            for (auto e:adj[nodeA]){
                //int nodeA=e[0];
                int nodeB=e.first;
                int w=e.second;

                if (dist[nodeB]>dist[nodeA]+w){
                    dist[nodeB]=dist[nodeA]+w;
                    if (!inqueue[nodeB]){
                        q.push(nodeB);
                        inqueue[nodeB]=true;
                        cnt[nodeB]++;
                        if (cnt[nodeB]>n)return -1;
                    }
                }
            }
        }

        int ans=0;
        for (int i=1;i<=n;i++){
            ans=max(dist[i],ans);
            if (dist[i]==INF)return -1;
        }

        return ans;
        
    }
};