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

vector<int> check(vector<vector<int>>& ans){
    int l=ans.size();
    for(int i=0;i<l;i++){
        bool c=true;
        for(int j=0;j<ans[i].size()-1;j++){
            if(__builtin_popcount(ans[i][j]^ans[i][j+1])!=1){
                c=false;break;
            }
        }
        if(c){
            cout<<i<<endl;
            for(int j=0;j<ans[i].size()-1;j++){
            cout<<__builtin_popcount(ans[i][j]^ans[i][j+1])<<" ";
                
        }cout<<endl;
            return ans[i];
        }
    }
}

vector<int> grayCode(int n) {
    int l=1<<n;
    vector<int> vec(l,0);
    
    for(int i=0;i<(1<<n);i++) vec[i]=i;
    vector<vector<int>> ans;
    findperm(0,ans,vec,l);
    vector<int> a=check(ans);
    return a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> ans=grayCode(3);
    for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
    cout<<endl;
    return 0;
}