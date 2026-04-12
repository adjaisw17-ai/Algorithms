#include<bits/stdc++.h>
using namespace std;

#define int long long
//MD-1
//https://atcoder.jp/contests/abc130/tasks/abc130_d
//Related to subarrays, might be two pointers;

int n,k;
vector<int> arr(n);
int sum = 0;

int can_eat(int x){
    if(sum+x<k){
        return 1;
    }
    return 0;
}

void solve(){
    cin >> n >> k;
    arr.resize(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    int head=-1, tail=0;
    int num_of_subs=0;
    while(tail<n){
        while(head+1<n && can_eat(arr[head+1])){
            head++;
            sum += arr[head];
        }
        num_of_subs += head-tail+1;
        if(head>=tail){
            sum -= arr[tail];
            tail++;
        }
        else{
            tail++;
            head=tail-1;
        }
    }
    int total_subs = 1LL*n*(n+1)/2;
    cout << total_subs - num_of_subs << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
}