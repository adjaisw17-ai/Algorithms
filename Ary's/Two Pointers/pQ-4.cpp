#include<bits/stdc++.h>
using namespace std;
//Container with most water.
//Leetcode Question : https://leetcode.com/problems/container-with-most-water/description/
int n;
vector<int> arr(n);

void solve(){
    cin >> n;
    arr.resize(n);
    for(int i=0; i<n; i++)cin>>arr[i];
    int l=0, r=n-1, ans=0;
    while(l<r){
        ans=max(ans,(r-l)*min(arr[l],arr[r]));
        if(arr[l]<arr[r]){
            l++;
        }else{
            r--;
        }
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
}