#include "alg.h"

// Solution 1: Top-Down Dp
int numTrees1(int n, vector<int> &dp) {
    if (dp[n] > 0) return dp[n];
    for (int i = 0; i < n; ++i) {
        dp[n] += numTrees1(i, dp) * numTrees1(n - 1 - i, dp);
    }
    return dp[n];
}

int numTrees1(int n) {
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    return numTrees1(n, dp);
}

// Solution 2: Bottom-Up Dp
int numTrees2(int n) {
    vector<int> dp(n + 1, 0);
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        for (int left = 0; left < i; left++) {
            dp[i] += dp[left] * dp[i - left - 1];
        }
    }
    return dp[n];
}

int main() {
    for (int i = 0; i < 10; ++i) {
        cout << numTrees1(i) << endl;
    }
}