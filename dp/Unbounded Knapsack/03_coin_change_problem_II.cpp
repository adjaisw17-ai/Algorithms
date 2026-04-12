#include <bits/stdc++.h>
using namespace std;

int solve(){
    int arr[]={3,1,2};
    int n=3;
    int sum=5;
    int t[n+1][sum+1];
    for(int i=0;i<n+1;i++){
        for(int j=0;j<sum+1;j++){
            if(j==0) t[i][j]=0;
            if(i==0) t[i][j]=INT_MAX;
        }
    }
    for(int j=1;j<sum+1;j++){
        if(j%arr[0]==0) t[1][j]=j/arr[0];
        else t[1][j]=INT_MAX;
    }
    for(int i=2;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            if(arr[i-1]<=j) t[i][j]=min(1+t[i][j-arr[i-1]],t[i-1][j]);
            else t[i][j]=t[i-1][j];
        }
    }
    return t[n][sum];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout<<solve()<<endl;
    return 0;
}