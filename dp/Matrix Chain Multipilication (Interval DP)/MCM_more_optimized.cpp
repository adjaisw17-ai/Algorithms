#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];

int solve(vector<int>& arr, int i, int j) {
    if (i >= j) {
        return 0;
    }
    
    if (dp[i][j] != -1) {
        return dp[i][j];
    }
    
    int min_cost = INT_MAX;
    
    for (int k = i; k <= j - 1; k++) {
        
        int left, right;
        
        // Optimize: Check if left subproblem is already solved
        if (dp[i][k] != -1) {
            left = dp[i][k];
        } else {
            left = solve(arr, i, k);
            dp[i][k] = left; // Store for future
        }
        
        // Optimize: Check if right subproblem is already solved
        if (dp[k + 1][j] != -1) {
            right = dp[k + 1][j];
        } else {
            right = solve(arr, k + 1, j);
            dp[k + 1][j] = right; // Store for future
        }
        
        // Calculate total cost
        int temp_ans = left + right + (arr[i - 1] * arr[k] * arr[j]);
        
        if (temp_ans < min_cost) {
            min_cost = temp_ans;
        }
    }
    
    return dp[i][j] = min_cost;
}

int main() {
    vector<int> arr = {40, 20, 30, 10, 30};
    memset(dp, -1, sizeof(dp));
    
    cout << "Minimum cost is: " << solve(arr, 1, arr.size() - 1) << endl;
    return 0;
}
