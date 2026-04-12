#include<bits/stdc++.h>
using namespace std;

//maybe X(i)=X(i-1)+X(i-5)+X(i-7) whatever and then base case 
//ek vector mein saare store karlo then output min of them

vector<int>noCoin;
const int INF=1e9+7;


int X(int x, vector<int> &coins,vector<int>&memo){

	if(x==0){
		return 0;
	}

    if (memo[x]!=0)return memo[x];

    int minCoins=INF;

	for (int i=0;i<coins.size();i++){
		if (x-coins[i]>=0){
			int coin=X(x-coins[i],coins,memo);
			//cout<<coin<<endl;
			//noCoin.push_back(coin);

            if (coin!=INF){
                minCoins=min(minCoins,coin+1);
            }
		}
	}

    return memo[x]=minCoins;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n,x;
	cin>>n>>x;

	vector<int>coins;
    vector<int>memo(x+1,0);

	for (int i=0;i<n;i++){
		int y;
		cin>>y;
		coins.push_back(y);
	}

	int ans=X(x,coins,memo);
    if (ans==INF){
        ans=-1;
    }
    cout<<ans<<endl;

	return 0;
}