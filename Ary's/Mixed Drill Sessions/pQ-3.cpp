#include<bits/stdc++.h>
using namespace std;

#define int long long

//MD-1
//https://codeforces.com/problemset/problem/782/B
//Good logical question.
//What we learnt?
//1. BS on Real Numbers.
//2. Output formatting of doubles.

int n;
vector<double> coordinates(n);
vector<double> speed(n);

bool check(double t){
    double L=-1e18, R=1e18;
    for(int i=0; i<n; i++){
        L=max(L,coordinates[i]-speed[i]*t);
        R=min(R,coordinates[i]+speed[i]*t);
    }
    return L<=R;
}


void solve(){  
    cin >> n;
    coordinates.resize(n);
    speed.resize(n);
    for(int i=0; i<n; i++){
        cin>>coordinates[i];
    }
    for(int i=0; i<n; i++){
        cin >> speed[i];
    }
    double lo=0, hi=1e9;
    for(int i=0; i<100; i++){
        double mid=lo+(hi-lo)/2;
        if(check(mid)){
            hi=mid;
        }
        else{
            lo=mid;
        }
    }
    cout << fixed << setprecision(10) << hi << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
}