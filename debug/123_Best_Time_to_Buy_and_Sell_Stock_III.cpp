#include "alg.h"

int maxProfit(vector<int> &prices) {
    if (prices.size() < 2) return 0;
    // dp[len][pos]
    vector<vector<int>> dp(3, vector<int>(prices.size(), 0));

    for (int k = 1; k <= 2; k++) {
        for (int i = 1; i < prices.size(); i++) {
            int max_val = 0;
            for (int j = 0; j < i; j++) {
                int x = prices[i] - prices[j] + dp[k-1][j-1];
                if (x > max_val) max_val = x;
            }
            dp[k][i] = max(dp[k][i - 1], max_val);
        }
    }
    return dp[2][prices.size() - 1];
}

int main() {
    vector<vector<int>> v = {{3, 3, 5, 0, 0, 3, 1, 4},
                             {1, 2, 3, 4, 5},
                             {7, 6, 4, 3, 2},
                             {3, 2, 6, 5, 0, 3}};
    for (auto v1: v)
        cout << maxProfit(v1) << endl;
}