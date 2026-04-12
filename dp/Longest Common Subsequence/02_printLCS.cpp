#include <bits/stdc++.h>
using namespace std;

string LCS(){
    string X="abcdgh",Y="abedfhr"; 
    int n=X.length(),m=Y.length();
    string t[n+1][m+1];
    for(int i=0;i<n+1;i++){
        for(int j=0;j<m+1;j++){
            if(i==0 || j==0) t[i][j]="";
        }
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            if(X[i-1]==Y[j-1]){
                t[i][j]=t[i-1][j-1]+X[i-1];
            }
            else{
                if(t[i-1][j].length()>=t[i][j-1].length()) t[i][j]=t[i-1][j];
                else t[i][j]=t[i][j-1];
            }
        }
    }
    for(int i=0;i<n+1;i++){
        for(int j=0;j<m+1;j++){
            cout<<"("<<i<<","<<j<<")="<<t[i][j]<<" ";
        }
        cout<<endl;
    }
    return t[n][m];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout<<LCS()<<endl;
    return 0;
}