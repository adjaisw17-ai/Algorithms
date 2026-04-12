//https://codeforces.com/problemset/problem/510/B

#include<bits/stdc++.h>
using namespace std;

using state = pair<char, pair<int,int>>;
#define F first
#define S second
int n,m;
vector<vector<int>> visited;
vector<string> matrix;

int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};

bool inside(int x, int y){
    if(x>=0&&x<n&&y>=0&&y<m)return true;
    return false;
}

vector<state> valid_neighbors(state cur){
    vector<state> res;
    for(int i=0; i<4; i++){
        int nx = cur.S.F+dx[i];
        int ny = cur.S.S+dy[i];
        if(inside(nx,ny) && matrix[nx][ny]==cur.F ){
            res.push_back({cur.F,{nx,ny}});
        }
    }
    return res;
}

bool dfs(state node, state parent){
    visited[node.S.F][node.S.S]=1;
    for(auto v: valid_neighbors(node)){
        if(!visited[v.S.F][v.S.S]){
            if(dfs(v,node))return true;
        }
        else if(v!=parent){
            return true;
        }
    }
    return false;
}

void solve(){
    cin >> n >> m;
    visited = vector<vector<int>>(n,vector<int>(m,0));
    matrix.resize(n+1);
    for(int i=0; i<n; i++){
        cin >> matrix[i];
    }
    
    bool ans=false;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!visited[i][j]){
                if(dfs({matrix[i][j],{i,j}},{'>',{-1,-1}})){cout<<"Yes"<<endl; return;}
            }
        }
    }
    cout << "No" << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
}