#include <bits/stdc++.h>
using namespace std;

bool check(int r,int c,vector<string>&board,int n){
    for(int i=0;i<n;i++){
        if(i==r) continue;
        if(board[i][c]=='Q') return false;
    }
    for(int i=0;i<n;i++){
        if(i==c) continue;
        if(board[r][i]=='Q') return false;
    }
    int rr=r-1,cc=c-1;
    while(rr>=0 && cc>=0){
        if(board[rr][cc]=='Q') return false;
        rr--;cc--;
    }
    rr=r+1;cc=c+1;
    while(rr<n && cc<n){
        if(board[rr][cc]=='Q') return false;
        rr++;cc++;
    }
    rr=r-1;cc=c+1;
    while(rr>=0 && cc<n){
        if(board[rr][cc]=='Q') return false;
        rr--;cc++;
    }
    rr=r+1;cc=c-1;
    while(rr<n && cc>=0){
        if(board[rr][cc]=='Q') return false;
        rr++;cc--;
    }
    return true;
}

void queens(int row,vector<vector<string>> & ans,vector<string>& board,int n){
    if(row==n){
        ans.push_back(board);
        return;
    }
    for(int col=0;col<n;col++){
        if(check(row,col,board,n)){
            board[row][col]='Q';
            queens(row+1,ans,board,n);
            board[row][col]='.';
        }
    }
    return;
}

vector<vector<string>> solveNQueens(int n) {
    vector<string> board(n);
    vector<vector<string>> ans;
    string s(n,'.');
    for(int i=0;i<n;i++) board[i]=s;
    queens(0,ans,board,n);
    return ans;
}

int main() {
    vector<vector<string>> ans=solveNQueens(4);
    for(auto x:ans){
        for(auto y:x){
            cout<<y<<" ";
        }
        cout<<endl;
    }
    return 0;
}