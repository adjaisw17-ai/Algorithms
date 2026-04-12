#include <bits/stdc++.h>
using namespace std;

void make(vector<vector<int>>& ans,vector<int>& vec,vector<int>& nums,int idx,int n){
    if(idx==n){
        ans.push_back(vec);
        return;
    }
    vec.push_back(nums[idx]);
    make(ans,vec,nums,idx+1,n);
    vec.pop_back();
    make(ans,vec,nums,idx+1,n);
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> vec;
    int n=nums.size();
    make(ans,vec,nums,0,n);
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> nums={1,2,3};
    vector<vector<int>> ans=subsets(nums);
    for(auto x: ans){
        for(auto y:x) cout<<y<<" ";
        cout<<endl;
    }
    return 0;
}