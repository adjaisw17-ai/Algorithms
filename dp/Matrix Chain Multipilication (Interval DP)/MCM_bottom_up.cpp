// Recommendation  :- Use MCM memoization with more optimized one

#include <bits/stdc++.h>
using namespace std;

int matrixMultiplication(vector<int>& arr) {
    int n = arr.size();
    
    // Create a 2D DP table. dp[i][j] stores the min cost to multiply matrices from i to j
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // L is the chain length of matrices being multiplied
    // L = 1 means a single matrix, cost is 0 (already handled by vector initialization)
    
    // We start solving for chains of length 2 to n-1
    for (int L = 2; L < n; L++) {
        
        // i is the starting matrix index
        for (int i = 1; i < n - L + 1; i++) {
            
            // j is the ending matrix index
            int j = i + L - 1;
            dp[i][j] = INT_MAX;
            
            // Try all possible split points k between i and j-1
            for (int k = i; k <= j - 1; k++) {
                
                // cost = left part + right part + cost of multiplying the two resulting matrices
                int cost = dp[i][k] + dp[k + 1][j] + (arr[i - 1] * arr[k] * arr[j]);
                
                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                }
            }
        }
    }
    
    // The answer for the entire chain from matrix 1 to n-1
    return dp[1][n - 1];
}

int main() {
    vector<int> arr = {40, 20, 30, 10, 30};
    
    cout << "Minimum cost is: " << matrixMultiplication(arr) << endl;
    return 0;
}
