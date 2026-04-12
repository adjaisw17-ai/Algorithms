#include<bits/stdc++.h>
using namespace std;

int n,k;
vector<int> arr(n);
int cnt0;

int can_eat(int x){
    int temp=cnt0;
    if(x==0)temp++;
    if(temp<=k){
        return 1;
    }
    return 0;
}

void solve(){
    cin >> n >> k;
    arr.resize(n);
    for(int i=0; i<n; i++)cin>>arr[i];
    cnt0=0;
    int ans=0;
    int head=-1, tail=0;
    while(tail<n){
        while(head+1<n && can_eat(arr[head+1])){
            head++;
            if(arr[head+1]==0){
                cnt0++;
            }
        }
        ans=max(head-tail+1,ans);
        if(tail<=head){
            if(arr[tail]==0)cnt0--;
            tail++;
        }
        else{
            tail++;
            head=tail-1;
        }
    }
    cout << ans << endl;
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
}