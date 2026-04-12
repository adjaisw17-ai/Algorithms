#include<bits/stdc++.h>
using namespace std;

//kth sybol in grammar.
//Leetcode question : https://leetcode.com/problems/k-th-symbol-in-grammar/description/


int generator(int cur, int n, int k){
    if(n==1){
        return cur;
    }
    if(k<=pow(2,n-2)){
        return generator(cur, n-1,k);
    }
    else{
        return generator(1-cur, n-1,k-pow(2,n-2));
    }
}

void solve(){
    int x,y;
    cin >> x >> y;
    cout << generator(0, x, y)<<endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
}