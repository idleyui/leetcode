#include "alg.h"

int minFallingPathSum(vector<vector<int>> &A) {
    int m = A.size(), n = A[0].size();
    vector<vector<int>> dp(2, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        dp[0][i] = A[0][i];
    }
    for (int i = 1; i < m; i++) {
        for (int j = 0; j < n; j++) {
            dp[1][j] = dp[0][j];
            if (j > 0) dp[1][j] = min(dp[0][j - 1], dp[1][j]);
            if (j < n - 1) dp[1][j] = min(dp[0][j + 1], dp[1][j]);
            dp[1][j] += A[i][j];
        }
        swap(dp[0], dp[1]);
    }

    int ans = INT_MAX;
    for (int i: dp[0]) {
        ans = min(ans, i);
    }
    return ans;
}

// Solution 2: use A directly
// https://leetcode.com/problems/minimum-falling-path-sum/discuss/186666/C%2B%2BJava-4-lines-DP

int main() {

}