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

int main() {

}