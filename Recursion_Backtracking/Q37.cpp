#include <bits/stdc++.h>
using namespace std;

bool check(int r,int c,vector<vector<char>>& board,char v){
    for(int i=0;i<9;i++){
        if(board[r][i]==v) return false;
        if(board[i][c]==v) return false;
        if(board[3*(r/3)+i/3][3*(c/3)+i/3]==v) return false;
    }
    return true;
}

bool solve(vector<vector<char>>& board){
    for(int row=0;row<9;row++)
    for(int col=0;col<9;col++){
        if(board[row][col]=='.'){
            for(char i='1';i<='9';i++){
                if(check(row,col,board,i)==true){
                    board[row][col]=i;
                    if(solve(board)) return true;
                    else board[row][col]='.';
                }
            }
        return false;  
        }
    }
    return true;
}

void solveSudoku(vector<vector<char>>& board) {
    solve(board);
}

int main() {
    vector<vector<char>> sudoku={{'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}};
    solveSudoku(sudoku);
    for(auto x:sudoku){
        for(auto y:x){
            cout<<y<<",";
        }
        cout<<endl;
    }
    return 0;
}