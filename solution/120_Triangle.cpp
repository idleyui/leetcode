#include "alg.h"

// bottom-up
int minimumTotal_1(vector<vector<int>> &triangle) {
    if (triangle.size() == 0) return 0;
    vector<int> dp = triangle[triangle.size() - 1];
    for (int i = triangle.size() - 2; i >= 0; i--) {
        vector<int> tmp_dp(triangle[i].size());
        for (int j = 0; j < triangle[i].size(); j++) {
            tmp_dp[j] = triangle[i][j] + (dp[j] < dp[j + 1] ? dp[j] : dp[j + 1]);
        }
        dp = tmp_dp;
    }
    return dp[0];
}


// top-down
int minimumTotal_2(vector<vector<int>> &triangle) {
    vector<int> dp(triangle.back().size(), INT_MAX);
    dp[0] = triangle[0][0];
    for (int i = 1; i < triangle.size(); i++) {
        for (int j = triangle[i].size() - 1; j >= 0; j--) {
            dp[j] = min(dp[max(j - 1, 0)], dp[j]);
            dp[j] += triangle[i][j];
        }
    }
    return *min_element(dp.begin(), dp.end());

}

int main() {
    vector<vector<int>> vv = {{2},
                              {3, 4},
                              {6, 5, 7},
                              {4, 1, 8, 3}};
    cout << minimumTotal(vv);
}