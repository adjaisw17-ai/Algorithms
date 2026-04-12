#include <bits/stdc++.h>
using namespace std;

void combination(int idx,vector<vector<int>>& ans,vector<int>& vec,vector<int>& arr,int target,int n){
    if(target==0){
        ans.push_back(vec);
        return;
    }
    for(int i=idx;i<n;i++){
        if(arr[i]>target) return;
        vec.push_back(arr[i]);
        combination(i,ans,vec,arr,target-arr[i],n);
        vec.pop_back();
    }
}
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    sort(candidates.begin(),candidates.end());
    int n=candidates.size();
    vector<vector<int>> ans;
    vector<int> vec;
    combination(0,ans,vec,candidates,target,n);
    return ans;
}
int main() {
    vector<int> w={2,3,6,7};
    int k=7;
    vector<vector<int>> a=combinationSum(w,k);
    for(auto x:a){
        for(auto y:x){
            cout<<y<<" ";
        }
        cout<<endl;
    }
    return 0;
}