#include <bits/stdc++.h>
using namespace std;

void macSubarraySum(vector<int>& arr) {
    int n=arr.size();
    int ansStart=-1,ansEnd=-1,start=-1;
    long long sum=0,maxi=LONG_MIN;
    for(int i=0;i<n;i++){
        if(sum==0) start=i;
        sum+=arr[i];
        if(sum > maxi){
            maxi=sum;
            ansStart=start;
            ansEnd=i;
        }

        if(sum < 0){
            sum=0;
        }
    }
    for(int i=ansStart;i<=ansEnd;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> arr={-2,1,-3,4,-1,2,1,-5,4};
    macSubarraySum(arr);
    return 0;
}