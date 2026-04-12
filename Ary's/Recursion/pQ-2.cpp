#include<bits/stdc++.h>
using namespace std;

//calculating ncr using its recursive relation.
int ncr(int n, int r){
    //Pruning
    if(r<0 || r>n){
        return 0;
    }
    //Base case
    if(r==0 || n==r){
        return 1;
    }
    return ncr(n-1,r)+ncr(n-1,r-1);
}

void solve(){
    int l,k;
    cin >> l >> k;
    cout << ncr(l,k) << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
}