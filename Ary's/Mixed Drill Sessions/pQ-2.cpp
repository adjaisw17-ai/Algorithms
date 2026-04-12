#include<bits/stdc++.h>
using namespace std;

#define int long long
//MD-1
//https://codeforces.com/problemset/problem/371/C
//I was unable to figure out that this was a BS question.
//if there is a thing to maximise of minimise, it might be BS, DP
//or any optimization algorithm.

//Mistakes happened in this question :-
//1.Binary Search of last true (Not the first true).
//2. Was counting number of 'b's not 'B's. Call it silly but it is what it is.
//3. Was applying reverse logic (rattu method).


int nb, ns, nc, pb, ps, pc,r,b=0,s=0,c=0;
string hamburger;

int check(int x){
    int value= max(0LL,(b*x-nb))*pb + max(0LL,(s*x-ns))*ps + max(0LL,(c*x-nc))*pc;
    if(value>r)return 0;
    return 1;
}

void solve(){
    cin >> hamburger;
    for(int i=0;i<hamburger.size();i++){
        if(hamburger[i]=='B')b++;
        if(hamburger[i]=='S')s++;
        if(hamburger[i]=='C')c++;
    }
    cin >> nb >> ns >> nc;
    cin >> pb >> ps >> pc;
    cin>>r;
    int lo=0, hi=1e13, mid, ans=-1;
    while(lo<=hi){
        mid = lo +(hi-lo)/2;
        if(check(mid)){
            ans=mid;
            lo = mid+1;
        }
        else{
            hi = mid-1;
        }
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
}