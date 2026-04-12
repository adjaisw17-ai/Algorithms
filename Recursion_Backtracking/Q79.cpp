#include <bits/stdc++.h>
using namespace std;

bool check(int idx,int r,int c,vector<vector<char>>& board,string word,int m,int n,int l){
    if(idx==l){
        return true;
    }
    if(r<0 || r>=m || c<0 || c>=n || board[r][c]!=word[idx]) return false;
    
        char temp=board[r][c];
        board[r][c]='0';
        
        bool ans=check(idx+1,r-1,c,board,word,m,n,l) || check(idx+1,r,c-1,board,word,m,n,l) || check(idx+1,r,c+1,board,word,m,n,l) || check(idx+1,r+1,c,board,word,m,n,l);
        
        board[r][c]=temp;
        return ans;
    
}

bool exist(vector<vector<char>>& board, string word) {
    int m=board.size();
    int n=board[0].size();
    int l=word.length();
    for(int i=0;i<m;i++)
    for(int j=0;j<n;j++){
    if(board[i][j]==word[0] && check(0,i,j,board,word,m,n,l)) return true;
    }
    return false;
}

int main() {
    vector<vector<char>> board={{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    string word="SEE";
    bool myans=exist(board,word);
    cout<<myans<<endl;
    return 0;
}