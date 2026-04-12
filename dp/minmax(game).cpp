#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int memo[1001][1001];

int solve(int i, int j, vector<int>& stones) {
    // Base case: No stones left
    if (i > j) return 0;
    
    // If already calculated
    if (memo[i][j] != -1) return memo[i][j];

    // Choice 1: Take the left stone
    // We get stones[i], but the opponent will play optimally for the rest
    int pickLeft = stones[i] - solve(i + 1, j, stones);

    // Choice 2: Take the right stone
    int pickRight = stones[j] - solve(i, j - 1, stones);

    // We take the maximum of these two results
    return memo[i][j] = max(pickLeft, pickRight);
}

int main() {
    vector<int> stones = {5, 3, 4, 5};
    int n = stones.size();
    
    // Initialize memo table with -1
    for(int i=0; i<n; i++) 
        for(int j=0; j<n; j++) memo[i][j] = -1;

    int result = solve(0, n - 1, stones);
    
    if (result > 0) cout << "Player 1 wins!";
    else if (result < 0) cout << "Player 2 wins!";
    else cout << "It's a tie!";
    
    return 0;
}