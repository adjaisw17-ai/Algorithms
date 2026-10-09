// See its soltuion for understanding of top down interval dp from youtube link -
// https://www.youtube.com/watch?v=eAG3QFsIPvo&t=1753s

#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define f(i, a, b) for (ll i = a; i < b; ++i)
const ll MOD=998244353;


void solve(){
    ll n;
    cin>>n;
    vector<ll> vec(n);
    for(ll i=0;i<=n;i++){
        cin>>vec[i];
    }
    vector<vector<ll>> dp(n,vector<ll>(n));
    for(ll len=0;len<n;len++){
        for(ll i=0,j=len;j<n;i++,j++){
            if(len==0){
                dp[i][j]=vec[i];
            }
            else if(len==1){
                dp[i][j]=max(vec[i],vec[j]);
            }
            else{
                ll val1=vec[i]+min(dp[i+1][j-1],dp[i+2][j]);
                ll val2=vec[j]+min(dp[i][j-2],dp[i+1][j-1]);
                dp[i][j]=max(val1,val2);
            }
        }
    }
    cout<<dp[0][n-1]<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

       solve();
    }
    return 0;
}
