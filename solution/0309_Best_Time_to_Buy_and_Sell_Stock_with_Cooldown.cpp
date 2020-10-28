#include "alg.h"

int maxProfit(vector<int> &prices) {
    if (prices.size() < 2) return 0;
    vector<int> tobuy(prices.size(), 0);
    vector<int> hold(prices.size(), 0);
    vector<int> rest(prices.size(), 0);
    hold[0] = -prices[0];
    rest[0] = INT_MIN;
    for (int i = 1; i < prices.size(); i++) {
        tobuy[i] = max(tobuy[i - 1], rest[i - 1]);
        hold[i] = max(tobuy[i - 1] - prices[i], hold[i - 1]);
        rest[i] = hold[i - 1] + prices[i];
    }
    return max(tobuy[prices.size() - 1], rest[prices.size() - 1]);
}

int maxProfit_2(vector<int> &prices) {
    int n = prices.size();
    if (n < 2) return 0;
    vector<vector<int>> dp(n, vector<int>(2, 0));
    dp[0][0] = -prices[0];
    dp[0][1] = 0;
    dp[1][0] = max(dp[0][0], -prices[1]);
    dp[1][1] = max(0, prices[1] + dp[0][0]);
    for (int i = 2; i < n; i++) {
        dp[i][0] = max(dp[i - 1][0], dp[i - 2][1] - prices[i]);
        dp[i][1] = max(dp[i - 1][1], prices[i] + dp[i - 1][0]);
    }
    return dp.back()[1];
}

int maxProfit_3(vector<int> &prices) {
    int n = prices.size();
    if (n < 2) return 0;
    int last_sell = max(0, prices[1] - prices[0]);
    int last_buy = max(-prices[0], -prices[1]);
    int last_two_sell = 0;
    for (int i = 2; i < n; i++) {
        int tmp = last_sell;
        last_sell = max(last_sell, last_buy + prices[i]);
        last_buy = max(last_buy, last_two_sell - prices[i]);
        last_two_sell = tmp;
    }
    return last_sell;
}

int main() {

}