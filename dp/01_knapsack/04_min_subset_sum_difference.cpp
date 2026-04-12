#include <bits/stdc++.h>
using namespace std;

bool solve(){
    int arr[]={1,1,2,3};
    int n=4;
    int sum=1;
    int s=0;
    for(int i=0;i<n;i++) s+=arr[i];
    bool t[n+1][s+1];
    for(int i=0;i<n+1;i++){
        for(int j=0;j<s+1;j++){
            if(i==0) t[i][j]=false;
            if(j==0) t[i][j]=true;
        }
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<s+1;j++){
            if(arr[i-1]<=j){
                t[i][j]=t[i-1][j-arr[i-1]] || t[i-1][j];
            }
            else{
                t[i][j]=t[i-1][j];
            }
        }
    }
    for(int j=0;j<s+1;j++){
        if(t[n][j]==1 && abs(s-2*j)==sum)
            return true;
    }
    
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    {
       cout<<solve()<<endl;
    }
    return 0;
}