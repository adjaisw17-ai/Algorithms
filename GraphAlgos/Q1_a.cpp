
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

//solving part a.
#include<bits/stdc++.h>
using namespace std;

using state=pair<int,int>;
#define F first
#define S second

int n,m;
const int INF = 1e9;
vector<vector<int>> visited, dist;
vector<string> grid;

int weight(state node){
    if(grid[node.F][node.S]=='#')return 1;
    return 0;
}

bool inside(int x, int y){
    if(x>=0&&x<n&&y>=0&&y<m)return true;
    return false;
}

vector<state> nbors(state node){
    vector<state> res;
    int dx[]={0,1,0,-1};
    int dy[]={1,0,-1,0};
    for(int dir=0; dir<4; dir++){
        int nx=node.F+dx[dir];
        int ny = node.S+dy[dir];
    
        if(inside(nx,ny))res.push_back({nx,ny});
    }
    return res;
}

void bfs(state sc){
    dist=vector<vector<int>>(n,vector<int>(m,INF));
    visited=vector<vector<int>>(n,vector<int>(m,0));

    //setup DS
    deque<state> dq;

    //setup Source
    dq.push_back(sc);
    dist[sc.F][sc.S]=0;

    //explore till empty
    while(!dq.empty()){
        state cur = dq.front(); dq.pop_front();
        for(auto v : nbors(cur)){
            if(!visited[v.F][v.S] && dist[v.F][v.S] > dist[cur.F][cur.S] + weight(v)){
                dist[v.F][v.S] = dist[cur.F][cur.S] + weight(v);
                if(weight(v))dq.push_back(v);
                else{dq.push_front(v);}
            }
        }
    }
}

void solve(){
    cin >> n >> m;
    grid.resize(n);
    state st,en;
    for(int i=0; i<n; i++){
        cin >> grid[i];
        for(int j=0;  j<m; j++){
            if(grid[i][j]=='S')st={i,j};
            if(grid[i][j]=='E')en={i,j};
        }  
    }
    bfs(st);
    cout << dist[en.F][en.S] << endl;

}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
}