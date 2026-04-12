#include<bits/stdc++.h>
using namespace std;

const int mod=1e9+7;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin>>n;

	char arr[n][n];
	int dp[n][n];

	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			cin>>arr[i][j];
			dp[i][j]=0;
		}
	}

	if (arr[0][0]=='*'){
		cout<<0<<endl;
		return 0;
	}
	dp[0][0]=1;

	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			if (arr[i][j]=='*'){
				dp[i][j]==0;
			}

			else{
				if (i>0 && arr[i-1][j]=='.'){
					dp[i][j]+=dp[i-1][j];
				}

				if(j>0 && arr[i][j-1]=='.'){
					dp[i][j]+=dp[i][j-1];
				}
			}

			dp[i][j]%=mod;
		}
	}

	cout<<dp[n-1][n-1]<<endl;


	return 0;
}