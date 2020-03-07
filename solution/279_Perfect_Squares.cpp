#include "alg.h"

// https://leetcode.com/problems/perfect-squares/discuss/71488/Summary-of-4-different-solutions-(BFS-DP-static-DP-and-mathematics)
// top-down
int sq(int n, vector<int> &dp) {
    if (dp[n] < INT_MAX) return dp[n];
    for (int i = 1; i * i <= n; i++) {
        int rt = sq(n - i * i, dp) + 1;
        dp[n] = min(dp[n], rt);
    }
    return dp[n];
}

int numSquares_1(int n) {
    vector<int> dp = vector<int>(n + 1, INT_MAX);
    dp[0] = 0;
    return sq(n, dp);
}

// bottom-up
int numSquares_2(int n) {
    vector<int> dp(n + 1, n + 1);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int left = 1; left * left <= i; left++) {
            dp[i] = min(dp[i], 1 + dp[i - left * left]);
        }
    }
    return dp[n];
}

int main() {
    for (int i = 0; i < 12; i++)
        cout << i << ' ' << numSquares_1(i) << ',';

}