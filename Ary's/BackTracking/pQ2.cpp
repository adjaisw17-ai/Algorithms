//Print all the permutations of an integer array which has all the elements distinct.
#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> arr(n), taken(n,0), perm(n);
int cnt=0;
void rec(int idx){
    if(idx==n){
        cnt++;
        for(int i=0; i<n; i++){
            cout << perm[i] << " ";
        }
        cout << endl;
        return;
    }
    for(int i=0; i<n; i++){
        if(!taken[i]){
            taken[i]=1;
            perm[idx]=arr[i];
            rec(idx+1);
            perm[idx]=-1;
            taken[i]=0;
        }
    }
}

void solve(){
    cin >> n;
    arr.resize(n);perm.resize(n);taken.resize(n,0);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    rec(0);
    cout <<cnt << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
}