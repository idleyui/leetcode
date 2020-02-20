#include "alg.h"

// https://leetcode.com/problems/minimum-path-sum/discuss/23457/C%2B%2B-DP
// same as 62 Unique Paths

// Solution 1: O(m*n) Dp
int minPathSum2(vector<vector<int>> &grid) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 && j == 0) dp[i][j] = 0;
            else if (i == 0) dp[i][j] = dp[i][j - 1];
            else if (j == 0) dp[i][j] = dp[i - 1][j];
            else {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]);
            }
            dp[i][j] += grid[i][j];
        }
    }
    return dp[m - 1][n - 1];
}

// Solution 2: O(n) Dp
int minPathSum(vector<vector<int>> &grid) {
    int m = grid.size(), n = grid[0].size();
    vector<int> cur(n, grid[0][0]);
    for (int i = 1; i < n; i++) {
        cur[i] = grid[0][i] + cur[i - 1];
    }
    for (int i = 1; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (j == 0) cur[j] = cur[j] + grid[i][j];
            else cur[j] = min(cur[j], cur[j - 1]) + grid[i][j];
        }
    }
    return cur[n - 1];
}

int main() {

}