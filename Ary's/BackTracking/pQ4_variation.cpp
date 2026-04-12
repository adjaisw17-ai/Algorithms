//Print all the combinations of size k of an n sized array.
//not necessarily distinct elements may be present.
#include<bits/stdc++.h>
using namespace std;

int n,k;
vector<int> arr, combination;

void rec(int idx){
    if(combination.size()==k){
        for(int i=0; i<k; i++){
            cout << combination[i] << " ";
        }
        cout << endl;
        return;
    }
    for(int i=idx; i<n; i++){
        if(i>idx && arr[i]==arr[i-1])continue;
        combination.push_back(arr[i]);
        rec(i+1);
        combination.pop_back();
    }
}

void solve(){
    cin >> n >> k;
    arr.resize(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    sort(arr.begin(),arr.end());
    rec(0);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
}