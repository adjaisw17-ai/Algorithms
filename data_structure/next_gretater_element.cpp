#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

vector<int> nextGreaterElement(vector<int>& a) {
    int n = a.size();
    vector<int> ans(n, -1); // Initialize with -1 for "not found"
    stack<int> s;

    // Traverse from right to left
    for (int i = n - 1; i >= 0; i--) {
        // 1. Pop elements smaller than or equal to current element
        while (!s.empty() && s.top() <= a[i]) {
            s.pop();
        }

        // 2. If stack isn't empty, the top is the Next Greater Element
        if (!s.empty()) {
            ans[i] = s.top();
        }

        // 3. Push current element to stack for the next iterations
        s.push(a[i]);
    }
    return ans;
}