//VERY GOOD QUESTION FOR REVISION.
/*
Ques 1. Given a grid with a starting
point and the ending point. Find:

    a.  Find the minimum no. of walls
    you need to break to go from
    points S to E.

    b.  If you can break <= K walls, 
    Find minimum moves needed.

    c.  Find all answer for (b) 
    for K in the range: 1 <= K <= N+M

    constrainsts: N,M<=100
*/

//solving part c.

#include<bits/stdc++.h>
using namespace std;

using state = vector<int>;

const int INF = 1e9;

int n,m,k_limit;
vector<string> grid;
vector<vector<vector<int>>> dist, visited;

vector<state> nbors(state node, int k){
    vector<state> res;
    int dx[] = {0,1,0,-1};
    int dy[] = {1,0,-1,0};
    for(int dir=0; dir<4; dir++){
        int nx = node[0]+dx[dir];
        int ny = node[1] + dy[dir];
        if(nx>=0&&nx<n&&ny>=0&&ny<m){
            int nz = node[2];
            if(grid[nx][ny]=='#')nz++;
            if(nz<=k_limit){
                res.push_back({nx,ny,nz});
            }
        }
    }
    return res;
}

void bfs(state sc , int k){
    dist = vector<vector<vector<int>>>(n,vector<vector<int>>(m,vector<int>(k+1,INF)));
    visited = vector<vector<vector<int>>>(n,vector<vector<int>>(m,vector<int>(k+1,0)));
    //setup DS
    queue<state> q;

    //setup Source
    q.push(sc);
    dist[sc[0]][sc[1]][sc[2]] = 0;

    //explore till empty;
    while(!q.empty()){
        state cur = q.front(); q.pop();
        if(visited[cur[0]][cur[1]][cur[2]])continue;

        //explore
        visited[cur[0]][cur[1]][cur[2]]=1;
        for(auto v : nbors(cur,k)){
            if(!visited[v[0]][v[1]][v[2]]){
                q.push(v);
                dist[v[0]][v[1]][v[2]] = dist[cur[0]][cur[1]][cur[2]] + 1;
            }
        }
    }
}

void solve(){
    cin >> n >> m ;
    grid.resize(n+1);
    state st,en;
    for(int i=0; i<n; i++){
        cin >> grid[i];
        for(int j=0; j<m; j++){
            if(grid[i][j]=='S')st={i,j,0};
            if(grid[i][j]=='E')en={i,j,INF};
        }
    }
    for(k_limit=1; k_limit<=n+m; k_limit++){
        bfs(st,k_limit);
        int ans = INF+1;
        for(int j=0; j<=k_limit; j++){
            ans = min(ans,dist[en[0]][en[1]][j]);
        }
        if(ans!=INF){
            cout << "YES\n" << ans << endl;
        }else cout << "NO\n" << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
}
