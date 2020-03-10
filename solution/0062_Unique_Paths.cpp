#include "alg.h"

// Solution 1: Top-Down with table
int dfs(vector<vector<int>> &visited, int m, int n, int x, int y) {
    if (visited[x][y]) return visited[x][y];
    if (x == m - 1 || y == n - 1) return 1;
    visited[x][y] = dfs(visited, m, n, x + 1, y) + dfs(visited, m, n, x, y + 1);
    return visited[x][y];
}

int uniquePaths1(int m, int n) {
    vector<vector<int>> visited(m, vector<int>(n, 0));
    return dfs(visited, m, n, 0, 0);
}

// Solution 2: Bottom-Up Dp
// https://leetcode.com/problems/unique-paths/discuss/22954/C%2B%2B-DP
// O(m*n)
int uniquePaths2_1(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 || j == 0) dp[i][j] = 1;
            else dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    return dp[m - 1][n - 1];
}

// O(n)
int uniquePaths2_2(int m, int n) {
    vector<int> pre(n, 1), cur(n, 1);
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            cur[j] = cur[j - 1] + pre[j];
        }
        swap(cur, pre);
    }
    return pre[n - 1];
}

int uniquePaths2_3(int m, int n) {
    vector<int> cur(n, 1);
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            cur[j] += cur[j - 1];
        }
    }
    return cur[n - 1];
}

int main() {
    cout << uniquePaths1(1, 1) << endl;
    cout << uniquePaths1(1, 10) << endl;
    cout << uniquePaths1(3, 2) << endl;
    cout << uniquePaths1(7, 3) << endl;
    cout << uniquePaths1(23, 12) << endl;
}