#include <bits/stdc++.h>
using namespace std;

bool solve(){
    int arr[]={1,5,11,5};
    int n=4; // no of elements
    // sum of elements in arr must be even so that we can have two subsets of equal sum
    // {1,5,5}=11 , {11}=11
    int sum=0;
    for(int i=0;i<n;i++) sum+=arr[i];
    if(sum%2==1) return false;
    else{
        // now the problem becomes same as 01_subset_sum
        sum/=2;
        int t[n+1][sum+1];
        for(int i=0;i<n+1;i++){
            for(int j=0;j<sum+1;j++){
                if(i==0) t[i][j]=false;
                if(j==0) t[i][j]=true;
            }
        }
        for(int i=1;i<n+1;i++){
            for(int j=1;j<sum+1;j++){
                if(arr[i-1]<=j) t[i][j]=t[i-1][j-arr[i-1]] || t[i-1][j];
                else t[i][j]=t[i-1][j];
            }
        }
        
        return t[n][sum];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    {
       cout<<solve()<<endl;
    }
    return 0;
}