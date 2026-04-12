#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int memo[100][1000];

int solve(int i, int W, vector<int>& weights, vector<int>& values) {
    // Base Case: No items left or no capacity left
    if (i == weights.size() || W == 0) return 0;

    if (memo[i][W] != -1) return memo[i][W];

    // Choice 1: Non-Pick (Skip the current item)
    int skip = solve(i + 1, W, weights, values);

    // Choice 2: Pick (Take the current item, if it fits)
    int take = 0;
    if (weights[i] <= W) {
        take = values[i] + solve(i + 1, W - weights[i], weights, values);
    }

    // Store and return the better of the two choices
    return memo[i][W] = max(take, skip);
}

int main() {
    vector<int> weights = {2, 3, 4, 5};
    vector<int> values = {3, 4, 5, 6};
    int capacity = 5;

    // Fill memo with -1
    for(int i=0; i<100; i++) for(int j=0; j<1000; j++) memo[i][j] = -1;

    cout << "Max Value: " << solve(0, capacity, weights, values) << endl;
    return 0;
}