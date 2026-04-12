#include<bits/stdc++.h>
using namespace std;

//MD-1
//MUST READ ITS txt file for more explanation.

//https://codeforces.com/problemset/problem/1777/C
//Very good question.

//A very repetitive set of problems based on minimizing
//or maximizing the gap.
//Also for these problems, answer will always be a subarray
//because there is no constraint on number of members in a team,

//example, 3 4 2 7 is smartness array
//there can be a team 7 2 3-> for which (max-min) nikalne ke
//liye sort karna padega, which is 2 3 7.
//in sorted form of smartness array, 2 3 4 7,
//there doesnt exist any as such window.
//but the thing is, there does exist 2 3 4 7 wali window.
//toh if 2 3 7 satisfies, 2 3 4 7 will also satisfy,
//and in both cases, the expected output will remain
//same i.e difference of max and min of the window.

//So in such problems, there is no case that will be left out,
//when we apply two pointers.

vector<int> divisors[100010];

void pre(){
    for(int i=1; i<=100000; i++){
        for(int j=i; j<=100000; j+=i){
            divisors[j].emplace_back(i);
        }
    }
}
//DS
int distinct=0;
int freq[100010];

void win_insert(int x, int k){
    for(auto v: divisors[x]){
        if(v>k)continue;
        if(freq[v]==0)distinct++;
        freq[v]++;
    }
}

void win_erase(int x,int k){
    for(auto v:divisors[x]){
        if(v>k)continue;
        freq[v]--;
        if(freq[v]==0)distinct--;
    }
}

void solve(){
    int n,m;
    cin >> n >> m;
    set<int> st;
    for(int i=0; i<n;i++){
        int x; cin >> x;
        st.insert(x);
    }
    vector<int> arr(st.begin(),st.end());
    int head=-1, tail=0,ans=1e9;
    while(tail<arr.size()){
        while(head+1<arr.size() && distinct<m){
            head++;
            win_insert(arr[head],m);
        }
        if(distinct==m){
            ans=min(ans,arr[head]-arr[tail]);
        }
        if(tail<=head){
            win_erase(arr[tail],m);
            tail++;
        }
        else{
            tail++;
            head=tail-1;
        }
    }
    if(ans==1e9){
        cout << -1 << endl;
    }else{ 
        cout << ans << endl;
    }
}


signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    pre();
    int t; cin >> t;
    while(t--){
        solve();
    }
} 