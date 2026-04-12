class Solution {
public:
    const int INF=1e9;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<int>dist(n+1,INF);
        dist[k]=0;
        for (int i=0;i<n;i++){
            for (auto e:times){
                int nodeA,nodeB,w;
                nodeA=e[0];
                nodeB=e[1];
                w=e[2];
                dist[nodeB]=min(dist[nodeB],dist[nodeA]+w);;
            }
        }
    int max=0;
    for (int i=1;i<=n;i++){
        if (dist[i]>max){
            max=dist[i];
        }
        if (dist[i]==INF)return -1;
    }
    return max;
        
    }
};