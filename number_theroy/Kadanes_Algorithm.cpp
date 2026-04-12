#include <bits/stdc++.h>
using namespace std;

long long macSubarraySum(vector<int>& arr) {
    int n=arr.size();
    long long sum=0,maxi=LONG_MIN;
    for(int i=0;i<n;i++){
        sum+=arr[i];

        if(sum > maxi){
            maxi=sum;
        }

        if(sum < 0){
            sum=0;
        }
    }
    return maxi;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> arr={-2,1,-3,4,-1,2,1,-5,4};
    cout<<macSubarraySum(arr)<<endl;
    return 0;
}