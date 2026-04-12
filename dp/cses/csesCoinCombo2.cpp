#include<bits/stdc++.h>
using namespace std;

//a thing to note here is that recursion approach gives TLE here 
//so we have to use iterative approach
//recursion approach gives stack overflow during recursion
//but looping doesnt give TLE

const int mod=1e9+7;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n,x;
	cin>>n>>x;

	vector<int>dp(x+1);
	vector<int>coins(n);
	
	dp[0]=1;

	for (int i=0;i<n;i++){
		cin>>coins[i];
	}

	sort(coins.begin(),coins.end());

	for (int i=0;i<n;i++){
		for (int j=1;j<=x;j++){
	
			if (j-coins[i]>=0){
				dp[j]=(dp[j]+dp[j-coins[i]])%mod;
				
			}
		}
	}
	cout<<dp[x]<<endl;

	return 0;
}