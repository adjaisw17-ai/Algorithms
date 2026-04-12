#include<bits/stdc++.h>
using namespace std;
//Check if s is subsequence of t;
void solve(){
    string s,t;
    cin >> s >> t;
    int i=0, j=0;
    while(i<s.size() && j<t.size()){
        if(s[i]==s[j]){
            i++;
            j++;
        }
        else{
            j++;
        }
    }
    if(i == s.size()){
        cout << "Yes";
    }else{cout << "No";}
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
}