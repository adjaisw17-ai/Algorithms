#include<bits/stdc++.h>
using namespace std;

//memo mein store karo number of ways to form i
//+ kardo upar wale se

// a thing to note here is that recrusion approach would give TLE 
//so we have to use iterative approach 

const int mod=1e9+7;

long long int X(int x,vector<long long int>&memo,vector<long long int>&coins){

	if (x==0){
		return 1;
	}

	if (memo[x]) return memo[x];

	for (int i=0;i<coins.size();i++){
		if (x-coins[i]>=0) memo[x]=(memo[x]+X(x-coins[i],memo,coins))%mod;
	}

	return memo[x];

}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n,x;
	cin>>n>>x;

	vector<long long int>memo(x+1,0);
	vector<long long int>coins(n);

	for (int i=0;i<n;i++){
		cin>>coins[i];
	}

	long long int ans=X(x,memo,coins);
	cout<<ans<<endl;

	return 0;
}