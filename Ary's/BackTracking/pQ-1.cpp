//Given an N times N board, place a knight in each row. 
//How many ways are there to place the knights with the 
//above condition given that no two knights attack each other?
#include<bits/stdc++.h>
using namespace std;

int n;
vector<vector<char>> board(n,vector<char>(n));
int cnt=0;

void output(){
    for(int i=0;i<n;i++){
        for(int j=0; j<n; j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl << "-------------" << endl;
}

int dx[]={-2,-1,1,2};
int dy[]={-1,-2,-2,-1};

int inside(int i, int j){
    if(i<n&&j<n&&i>=0&&j>=0)return 1;
    return 0;
}

int can_place(int i, int j){
    for(int k=0;k<4;k++){
        if(inside(i+dy[k],j+dx[k])&&board[i+dy[k]][j+dx[k]]=='K')return 0; 
    }
    return 1;
}

void rec(int level){
    if(level==n){
        cnt++;
        output();
        return;
    }
    for(int col=0; col<n;col++){
        if(can_place(level,col)){
            board[level][col]='K';
            rec(level+1);
            board[level][col]='.';
        }
    }
    
    
}

void solve(){
    //input
    cin >> n;
    //precomputation on input (here creation of board)
    board.resize(n);
    for(int i=0; i<n; i++){
        board[i].resize(n,'.');
    }
    rec(0);
    cout<<endl << "Total no. of configurations = "<<cnt << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
}