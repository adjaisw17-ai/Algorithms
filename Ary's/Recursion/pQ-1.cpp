#include<bits/stdc++.h>
using namespace std;
//Recursion Foundation Class Question.
//First palindrome function was designed by me.

// int isPalindrome(string t, int l, int r){
//     if(l>r){
//         return 1;
//     }
//     if(t[l]==t[r]){
//         l++;
//         r--;
//         return isPalindrome(t,l,r);
//     }
//     return 0;
// }

int isPalindrome(string t, int l, int r){
    if(l>=r){
        return 1;
    }
    if(t[l] != t[r]){
        return 0;
    }
    return isPalindrome(t,l+1,r-1);
}

void solve(){
    string s;
    cin >> s;
    cout << isPalindrome(s,0,s.size()-1);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
}