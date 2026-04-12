#include <bits/stdc++.h>
using namespace std;

int static t[1001][1001];
int LCS(string X,string Y,int n,int m){
    if(n==0||m==0) return 0; 
    if(t[n][m]!=-1) return t[n][m];
    if(X[n-1]==Y[m-1]) t[n][m]=1+LCS(X,Y,n-1,m-1);
    else{
        t[n][m]= max(LCS(X,Y,n-1,m),LCS(X,Y,n,m-1));
    }
    return t[n][m];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string X="abcdgh",Y="abedfhr";
    int n=X.length(),m=Y.length();

    memset(t,-1,sizeof(t));
    cout<<LCS(X,Y,n,m)<<endl;
    return 0;
}