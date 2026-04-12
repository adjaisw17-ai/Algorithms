#include<bits/stdc++.h>
using namespace std;

//Atcoder class question
//https://atcoder.jp/contests/abc115/tasks/abc115_d

#define int long long
#define f first
#define s second

vector<pair<int,int>> level_count(50);

void pre(){
    level_count[0] = {0,1};
    for(int i=1; i<=50; i++){
        level_count[i] = level_count[i-1];
        level_count[i].f*=2;
        level_count[i].f+=2;
        level_count[i].s*=2;
        level_count[i].s+=1;
    }
}

pair<int,int> getcnt(int n, int x){
    pair<int,int> ans = {0,0};
    //pruning
    if(x==0)return ans;
    //Base case
    if(n==0){
        return {0,1};
    }
    if(x>=1){
        ans.f += 1;
        x-=1;
    }
    if(x>=level_count[n-1].f+level_count[n-1].s){
        ans.f += level_count[n-1].f;
        ans.s += level_count[n-1].s;
        x -= level_count[n-1].f+level_count[n-1].s;
    }
    else{
        auto temp = getcnt(n-1,x);
        ans.f += temp.f;
        ans.s += temp.s;
        return ans;
    }
    if(x>=1){
        ans.s+=1;
        x-=1;
    }
    if(x>=level_count[n-1].f+level_count[n-1].s){
        ans.f += level_count[n-1].f;
        ans.s += level_count[n-1].s;
        x -= level_count[n-1].f+level_count[n-1].s;
    }
    else{
        auto temp = getcnt(n-1,x);
        ans.f += temp.f;
        ans.s += temp.s;
        return ans;
    }
    if(x>=1){
        ans.f+=1;
        x-=1;
    }
    return ans;
}

void solve(){
    pre();
    int level,x;
    cin >> level >> x;
    cout << getcnt(level,x).s << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
}