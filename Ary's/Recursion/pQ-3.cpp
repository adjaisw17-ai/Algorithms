#include<bits/stdc++.h>
using namespace std;
//Recursion Foundation Class Question
void printer(int n){
    if(n==1){
        cout << 1 << endl;
        return;
    }
    cout << n << endl;
    printer(n-1);
    cout << n << endl;
}

void solve(){
    int k;
    cin >> k;
    printer(k);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
}