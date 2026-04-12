class Solution {
public:
    const int INF=1e9;
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<pair<int,int>>adj[n];
        vector<vector<int>>dist(n,vector<int>(n,INF));

        for (auto e:edges){
            adj[e[0]].push_back(make_pair(e[1],e[2]));
            adj[e[1]].push_back(make_pair(e[0],e[2]));
            dist[e[0]][e[1]]=e[2];
            dist[e[1]][e[0]]=e[2];
        }

        for (int i=0;i<n;i++){
            dist[i][i]=0;
        }

        for (int k=0;k<n;k++){
            for (int i=0;i<n;i++){
                for (int j=0;j<n;j++){
                    dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }

        int node;
        int least=INF;
        for (int i=0;i<n;i++){
            int count=0;
            for (int j=0;j<n;j++){
                if (dist[i][j]<=distanceThreshold)count++;
            }
            if (least>=count){
                least=count;
                node=i;
            }

        }
        return node;

    }
};