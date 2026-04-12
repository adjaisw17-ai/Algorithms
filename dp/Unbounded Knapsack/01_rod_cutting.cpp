#include <bits/stdc++.h>
using namespace std;

int solve(){
    int length[]={1,2,3,4,5,6,7,8};
    int price[]={1,5,8,9,10,17,17,20};
    int n=8;
    int t[n+1][n+1];
    for(int i=0;i<n+1;i++){
        for(int j=0;j<n+1;j++){
            if(i==0 || j==0) t[i][j]=0;
        }
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<n+1;j++){
            if(length[i-1]<=j){
                t[i][j]=max(price[i-1]+t[i][j-length[i-1]],t[i-1][j]);
            }
            else{
                t[i][j]=t[i-1][j];
            }
        }
    }
    
    for(int i=0;i<n+1;i++){
        for(int j=0;j<n+1;j++){
            cout<<"("<<i<<","<<j<<")="<<t[i][j]<<" ";
        }
        cout<<endl;
    }
    return t[n][n];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    {
       cout<<solve()<<endl;
    }
    return 0;
}