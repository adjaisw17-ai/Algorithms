#include <bits/stdc++.h>
using namespace std;

bool solve(){
    int arr[]={1,3,7,8,10};
    int n=5;
    int sum=11;
    bool t[n+1][sum+1];
    for(int i=0;i<n+1;i++){
        for(int j=0;j<sum+1;j++){
            if(i==0) t[i][j]=false;
            if(j==0) t[i][j]=true;
        }
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            if(arr[i-1]<=j){
                t[i][j]=t[i-1][j-arr[i-1]] || t[i-1][j];
            }
            else{
                t[i][j]=t[i-1][j];
            }
        }
    }
    
    for(int i=0;i<n+1;i++){
        for(int j=0;j<sum+1;j++){
            cout<<"("<<i<<","<<j<<")="<<t[i][j]<<" ";
        }
        cout<<endl;
    }
    return t[n][sum];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    {
       cout<<solve()<<endl;
    }
    return 0;
}