#include <bits/stdc++.h>
using namespace std;

void findperm(int idx,vector<vector<int>>& ans,vector<int>& nums,int n){
    if(idx==n){
        ans.push_back(nums);
        return;
    }
    for(int i=idx;i<n;i++){
        int c=nums[idx];
        nums[idx]=nums[i];
        nums[i]=c;
        findperm(idx+1,ans,nums,n);

        c=nums[idx];
        nums[idx]=nums[i];
        nums[i]=c;
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>>ans;
    int n=nums.size();
    findperm(0,ans,nums,n);
    return ans;
}

int main() {
    vector<int> nums={1,2,3};
    vector<vector<int>> ans=permute(nums);
    for(auto x:ans){
        for(auto y:x){
            cout<<y<<" ";
        }
        cout<<endl;
    }
    return 0;
}