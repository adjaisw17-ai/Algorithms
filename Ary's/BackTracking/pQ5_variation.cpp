//Homework question- Print all the subsets of an integer array of not necessarily distinct elements.
#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> arr, combination;
vector<vector<int>>matrix;

void printer(){
    for(int i=0; i<matrix.size(); i++){
        for(int j=0; j<matrix[i].size();j++){
            cout << matrix[i][j] << " ";
        }
        cout << " | ";
    }
    cout<<endl;
}

void rec(int idx,int k){
    if(combination.size()==k){
        matrix.push_back(combination);
    }
    for(int i=idx; i<n; i++){
        if(i>idx && arr[i]==arr[i-1])continue;
        combination.push_back(arr[i]);
        rec(i+1,k);
        combination.pop_back();
    }
}

void solve(){
    cin >> n;
    arr.resize(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    sort(arr.begin(),arr.end());
    for(int i=1;i<=n;i++){
        rec(0,i);
    }
    printer();
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
}