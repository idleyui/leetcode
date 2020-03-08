#include "alg.h"

int maximalSquare(vector<vector<char>> &matrix) {
    int n = matrix.size(), m = n > 0 ? matrix[0].size() : 0, max_sq = 0;
    vector<vector<int>> dp;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == '1') {
                dp.push_back({i, j, i, j});
            }
        }
    }

    while (dp.size() > 0) {
        max_sq = (dp[0][2] - dp[0][0] + 1) * (dp[0][2] - dp[0][0] + 1);
        cout << max_sq;
        vector<vector<int>> new_dp;
        for (vector<int> &v: dp) {
            if (v[2] == n - 1 || v[3] == m - 1) continue;
            bool exp = true;
            for (int i = v[0]; i <= v[2] + 1 && exp; i++) {
                if (matrix[i][v[3] + 1] == '0') exp = false;
            }
            for (int i = v[1]; i <= v[3] + 1 && exp; i++) {
                if (matrix[v[2] + 1][i] == '0') exp = false;
            }
            if (exp) new_dp.push_back({v[0], v[1], v[2] + 1, v[3] + 1});
        }
        dp = new_dp;
    }

    return max_sq;
}

// https://leetcode.com/problems/maximal-square/discuss/61935/6-lines-Visual-Explanation-O(mn)
//https://leetcode.com/problems/maximal-square/discuss/61802/Extremely-Simple-Java-Solution-%3A)
int maximalSquare_2(vector<vector<char>> &matrix) {
    int n = matrix.size();
    if (n == 0) return 0;
    int m = matrix[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));
    int sq = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dp[i][j] = matrix[i][j] - '0';
            if (matrix[i][j] == '1' && i && j) {
                dp[i][j] += min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]});
            }
            sq = max(sq, dp[i][j]);
        }
    }

    return sq * sq;
}

//space optim
//https://leetcode.com/problems/maximal-square/discuss/61803/C%2B%2B-space-optimized-DP

int main() {

}