#include <bits/stdc++.h>
using namespace std;

// Create a static global DP matrix initialized with -1
// Size depends on the maximum constraints given in the problem
int dp[1001][1001];

int solve(vector<int>& arr, int i, int j) {
    if (i >= j) {
        return 0;
    }
    
    // Check if the value is already computed
    if (dp[i][j] != -1) {
        return dp[i][j];
    }
    
    int min_cost = INT_MAX;
    
    for (int k = i; k <= j - 1; k++) {
        int temp_ans = solve(arr, i, k) + solve(arr, k + 1, j) + (arr[i - 1] * arr[k] * arr[j]);
        
        if (temp_ans < min_cost) {
            min_cost = temp_ans;
        }
    }
    
    // Store the calculated result in the DP table before returning
    return dp[i][j] = min_cost;
}

int main() {
    vector<int> arr = {40, 20, 30, 10, 30};
    int n = arr.size();
    
    // Initialize the DP table with -1
    memset(dp, -1, sizeof(dp));
    
    cout << "Minimum cost of multiplication is: " << solve(arr, 1, n - 1) << endl;
    
    return 0;
}
