#include<bits/stdc++.h>
using namespace std;

//normal dp nahi kar paega 
//bcoz prices are different so how can u say ki dp[i-1]+something
//i price hai
//so we can have i-price[1],i-price[2],i-price[3] and so onn.
//now how to keep track of pages with that

//like eerik says, i can buuy it or skip it, if remaining money>0 then i can buy it or skip it
//its like a fkin max subarray problem
//2D array where dp[i][j] i is the index till which we go 
//and j is the money

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n,x;
	cin>>n>>x;

	vector<int>prices(n);
	vector<int>pages(n);

	for (int i=0;i<n;i++){
		cin>>prices[i];
	}

	for(int i=0;i<n;i++){
		cin>>pages[i];
	}

	vector<vector<int>>dp(n+1,vector<int>(x+1,0));
	//base case?
	//if khareeda then dp[i][j]=max(dp[i+1][j-prices[i]]+pages[i],)
	dp[0][0]=0;
	for (int j=0;j<=x;j++){
		if (prices[0]<=j){
			dp[0][j]=pages[0];
		}
	}
	for (int i=1;i<n;i++){
		for (int j=0;j<=x;j++){
			dp[i][j]=dp[i-1][j];

			if (prices[i]<=j){
				dp[i][j]=max(dp[i][j],dp[i-1][j-prices[i]]+pages[i]);
			}
		}
	}

	cout<<dp[n-1][x];
	return 0;
}