//https://cses.fi/problemset/task/1193

#include<bits/stdc++.h>
using namespace std;

const int INF= 100;
using state = pair<int,int>;
#define F first
#define S second

int n,m;
vector<string> matrix;
vector<vector<int>> visited, distance_from_source;
vector<vector<state>> parent_node;

// void printer(){
//     for(int i=0; i<n; i++){
//         for(int j=0; j<m; j++){
//             cout << distance_from_source[i][j] << '\t';
//         }
//         cout << endl;
//     }
//     cout << endl;
// }

int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};

bool inside(int x, int y){
    if(x>=0&&x<n&&y>=0&&y<m)return true;
    return false;
}

vector<state> valid_neighbors(state current_node){
    vector<state> res;
    for(int dir=0; dir<4; dir++){
        int nx = current_node.F+dx[dir];
        int ny = current_node.S+dy[dir];
        if(inside(nx,ny)&&matrix[nx][ny]!='#'){
            res.push_back(make_pair(nx,ny));
        }
    }
    return res;
}

void bfs(state st){
    queue<state> q;
    //ADD SOURCE
    q.push(st);
    distance_from_source[q.front().F][q.front().S]=0;
    //INITIATE BFS
    while(!q.empty()){
        state cur = q.front(); q.pop();
        if(visited[cur.F][cur.S])continue;
        visited[cur.F][cur.S] = 1;
        for(state v: valid_neighbors(cur)){
            if(!visited[v.F][v.S]){
                q.push(v);
                distance_from_source[v.F][v.S]=distance_from_source[cur.F][cur.S]+1;
                parent_node[v.F][v.S]=cur;
            }
        }
        // cout << cur.F << " " << cur.S << endl;
        // printer();
    }
}

void solve(){
    cin >> n >> m;
    visited = vector<vector<int>>(n,vector<int>(m,0));
    distance_from_source = vector<vector<int>>(n,vector<int>(m,INF));
    parent_node = vector<vector<state>>(n,vector<state>(m,{-1,-1}));
    matrix.resize(n);
    for(int i=0; i<n; i++){
        cin >> matrix[i];
    }
    
    state st, en;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(matrix[i][j]=='A'){
                st={i,j};
            }
            else if(matrix[i][j]=='B'){
                en={i,j};
            }
        }
    }
    bfs(st);       
    // printer();

    if(distance_from_source[en.F][en.S]==INF)cout << "NO\n";
    
    else{
        cout << "YES\n" << distance_from_source[en.F][en.S] << endl;
        state i=en;
        vector<state> path;
        while(i!=make_pair(-1,-1)){
            path.push_back(i);
            i = parent_node[i.F][i.S];
        }  
        reverse(path.begin(),path.end());
        for(int i=1; i<path.size(); i++){
            int cx = path[i].F-path[i-1].F;
            int cy = path[i].S - path[i-1].S;
            if(cx==1)cout << "D";
            if(cx==-1)cout <<"U";
            if(cy==1)cout<<"R";
            if(cy==-1)cout<<"L";
        } 
        cout << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
}