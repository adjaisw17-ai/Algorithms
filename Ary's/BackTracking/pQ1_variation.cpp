//Given an NxN board, place knights in each row.
//How many ways are there to place the knights with the 
//above condition given that no two knights attack each other?
#include<bits/stdc++.h>
using namespace std;

int n;
vector<vector<char>> board(n,vector<char>('.'));

void printer(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl << "------------" << endl;
}

bool inside(int row, int col){
    if(row>=0&&row<n&&col>=0&&col<n)return true;
    return false;
}

int dx[]={-2,-1,1,2};
int dy[]={-1,-2,-2,-1};

bool can_place(int row, int col){
    for(int i=0; i<4; i++){
        if(inside(row+dy[i],col+dx[i])&&board[row+dy[i]][col+dx[i]]=='K')return false;
    }
    return true;
}

void backtracking(int x, int y){
    if(x==n){
        printer();
        return;
    }
    //choices-place or dont place;
    {
        if(can_place(x,y)){
            board[x][y]='K';
            if(y!=(n-1)){
            backtracking(x,y+1);
            }
            else{
              backtracking(x+1,0);
            }
            board[x][y]='.';
        }
    }
    {
        if(y==n-1){
            backtracking(x+1,0);
        }
        else{
            backtracking(x,y+1);
        }
    }
    

    
}

void solve(){
    cin >> n;
    board.resize(n);
    for(int i=0; i<n; i++)board[i].resize(n,'.');
    backtracking(0,0);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
}