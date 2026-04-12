#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string manachers(string s) {
    // 1. Pre-process the string
    string T = "#";
    for (char c : s) {
        T += c;
        T += "#";
    }

    int n = T.length();
    vector<int> P(n, 0);
    int C = 0, R = 0;

    for (int i = 0; i < n; i++) {
        // Find the mirror of i relative to C
        int i_mirror = 2 * C - i;

        // Use symmetry to skip work
        if (i < R) {
            P[i] = min(R - i, P[i_mirror]);
        }

        // Attempt to expand around center i
        while (i + 1 + P[i] < n && i - 1 - P[i] >= 0 && 
               T[i + 1 + P[i]] == T[i - 1 - P[i]]) {
            P[i]++;
        }

        // Update C and R if the palindrome centered at i expands past R
        if (i + P[i] > R) {
            C = i;
            R = i + P[i];
        }
    }

    // 2. Find the maximum radius in P
    int maxLen = 0;
    int centerIndex = 0;
    for (int i = 0; i < n; i++) {
        if (P[i] > maxLen) {
            maxLen = P[i];
            centerIndex = i;
        }
    }

    // 3. Extract the original substring
    int start = (centerIndex - maxLen) / 2;
    return s.substr(start, maxLen);
}

int main() {
    string s = "babad";
    cout << "Longest Palindromic Substring: " << manachers(s) << endl;
    return 0;
}