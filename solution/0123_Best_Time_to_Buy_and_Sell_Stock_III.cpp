#include "alg.h"

// Solution 1
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/discuss/39611/Is-it-Best-Solution-with-O(n)-O(1).
int maxProfit(vector<int> &prices) {
    int hold1 = INT_MIN, hold2 = INT_MIN, sell1 = 0, sell2 = 0;
    for (int price: prices) {
        sell1 = max(hold1 + price, sell1);
        sell2 = max(hold2 + price, sell2);
        hold1 = max(-price, hold1);
        hold2 = max(sell1 - price, hold2);
    }
    return sell2;
}

int maxProfit_2(vector<int> &prices) {
    int cost1 = INT_MAX, cost2 = INT_MAX, profit1 = 0, profit2 = 0;
    for (int p: prices) {
        cost1 = min(cost1, p); // min val
        profit1 = max(profit1, p - cost1);
        cost2 = min(cost2, p - profit1); // min val after first buy
        profit2 = max(profit2, p - cost2);
    }
    return profit2;
}

// naive dp, time exceeded
int maxProfit(vector<int> &prices) {
    if (prices.size() < 2) return 0;
    // dp[len][pos]
    vector<vector<int>> dp(3, vector<int>(prices.size(), 0));

    for (int k = 1; k <= 2; k++) {
        for (int i = 1; i < prices.size(); i++) {
            int max_val = prices[i] - prices[0];
            for (int j = 1; j <= i; j++) {
                int x = prices[i] - prices[j] + dp[k - 1][j - 1];
                if (x > max_val) max_val = x;
            }
            dp[k][i] = max(dp[k][i - 1], max_val);
        }
    }
    return dp[2][prices.size() - 1];
}


int maxProfit(vector<int> &prices) {
    if (prices.size() < 2) return 0;
    vector<vector<int>> profit(2, vector<int>(prices.size(), 0));
    int max_profit = 0, min_price = prices[0];
    for (int i = 1; i < prices.size(); i++) {
        max_profit = max(max_profit, prices[i] - min_price);
        min_price = min(min_price, prices[i]);
        profit[0][i] = max_profit;
        profit[1][i] = max_profit;
        // cout << max_profit;
    }
    // cout << endl;
    for (int i = 1; i < prices.size(); i++) {
        if (profit[0][i] <= 0) continue;
        for (int j = 1; j < i; j++) {
            profit[1][i] = max(profit[1][i], profit[0][j - 1] + (prices[i] - prices[j]));
        }
        profit[1][i] = max(profit[1][i], profit[1][i - 1]);
        // cout << profit[1][i];

    }
    return profit[1][prices.size() - 1];

}

int main() {
    vector<vector<int>> v = {{3, 3, 5, 0, 0, 3, 1, 4},
                             {1, 2, 3, 4, 5},
                             {7, 6, 4, 3, 2},
                             {3, 2, 6, 5, 0, 3}};
    for (auto v1: v)
        cout << maxProfit(v1) << endl;
}