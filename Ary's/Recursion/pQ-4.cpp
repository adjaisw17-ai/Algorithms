#include<bits/stdc++.h>
using namespace std;

//Tower of Hanoi, kth move.

void movedisks(int n, int from ,int to, int extra, int k){
    //Base case
    if(n==0) return;
    //Main idea
    if(k<pow(2,n-1)){
        movedisks(n-1,from,extra,to,k);
    }
    if(k==pow(2,n-1)){
        cout << "From " << from << " to " << to << endl;
    }
    if(k>pow(2,n-1)){
        movedisks(n-1,extra, to, from,k-pow(2,n-1));
    }
}

void solve(){
    int x;
    cin >> x;
    movedisks(3,1,3,2,x);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
}