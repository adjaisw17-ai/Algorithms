#include<bits/stdc++.h>
using namespace std;

//iterative approach hi lagaenge as constraint 10^6 mein hai
//dp ka ek memo banaenge, now we have to make a function which 
//finds the digits of the number
//har baar subtract karne ke baad digits ka vector banao
//fir kaise karein wapas se
//in iterative when we reach n all n-1 have been calculated
//so all we have to do is check for all digits that is n-d

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin>>n;
	
	vector<int>dp(n+1,0);
	dp[0]=0;

	for (int i=1;i<=n;i++){
		int k=i;
		while (k>0){
			int d=k%10;
			if (d>0 && d<=i){
				if (dp[i]==0){
					dp[i]=dp[i-d]+1;
				}

				else{
					dp[i]=min(dp[i],dp[i-d]+1);
				}
			}

			k/=10;
		}
	}

	cout<<dp[n]<<endl;


	return 0;
}

