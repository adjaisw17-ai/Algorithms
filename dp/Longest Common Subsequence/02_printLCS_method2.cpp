#include <bits/stdc++.h>
using namespace std;

string LCS(){
    string X="abcdgh",Y="abedfhr"; 
    int n=X.length(),m=Y.length();
    int t[n+1][m+1];
    for(int i=0;i<n+1;i++){
        for(int j=0;j<m+1;j++){
            if(i==0 || j==0) t[i][j]=0;
        }
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            if(X[i-1]==Y[j-1]){
                t[i][j]=1+t[i-1][j-1];
            }
            else{
                t[i][j]=max(t[i-1][j],t[i][j-1]);
            }
        }
    }
    string s="";
    int i=n,j=m;
    while(i>0 && j>0){
        if(X[i-1]==Y[j-1]){
            s=X[i-1]+s;
            i--;j--;    
        }
        else{
            if(t[i-1][j]>t[i][j-1]){
                i--;
            }
            else{
                j--;
            }
        }
    }
    return s;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout<<LCS()<<endl;
    return 0;
}