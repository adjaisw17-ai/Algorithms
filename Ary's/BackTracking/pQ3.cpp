//Generate all n sized arrays whose sum is k;
#include<bits/stdc++.h>
using namespace std;

int n,k;
vector<int> perm;
int total=0;

void rec(int idx){
    if(total>k)return;

    if(idx==n){
        if(total==k){
        for(int i=0; i<n; i++)cout << perm[i] << " ";
        cout << endl;
        }
        return;
    }

    for(int i=1; i<=k; i++){
        total+=i;
        perm[idx]=i;
        rec(idx+1);
        total-=i;
    }
}

void solve(){
    cin >> n >> k;
    perm.resize(n);
    rec(0);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
}