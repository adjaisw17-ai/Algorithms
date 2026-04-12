//print all the permutations of an integer array of size n,
//which may contain multiple copies of a single element.
#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> arr, perm;
map<int,int> freq;

void rec(int idx){
    if(idx==n){
        for(int i=0; i<n; i++){
            cout << perm[i] << " ";
        }
        cout << endl;
        return;
    }

    for(auto &v:freq){
        if(v.second>0){
            v.second--;
            perm[idx]=v.first;
            rec(idx+1);
            v.second++;
        }
    }
}

void solve(){
    cin >> n;
    arr.resize(n); perm.resize(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
        freq[arr[i]]++;
    }
    rec(0);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
}