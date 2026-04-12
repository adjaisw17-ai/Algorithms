#include <bits/stdc++.h>
using namespace std;

void findperm(vector<vector<int>>& ans,vector<int>& vec,vector<int>& nums,vector<int>& hash,int n){
    if(vec.size()==n){
        ans.push_back(vec);
        return;
    }
    for(int i=0;i<n;i++){
        if(hash[i]==1) continue;
        hash[i]=1;
        vec.push_back(nums[i]);
        findperm(ans,vec,nums,hash,n);
        
        vec.pop_back();
        hash[i]=0;
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>>ans;
    vector<int>vec;
    int n=nums.size();
    vector<int> hash(n,0);
    findperm(ans,vec,nums,hash,n);
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