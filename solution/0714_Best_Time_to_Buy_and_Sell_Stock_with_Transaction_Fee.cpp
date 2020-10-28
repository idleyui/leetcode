#include "alg.h"

int maxProfit(vector<int> prices, int fee) {
    if (prices.empty()) return 0;
//    buy and sell profit
    vector<int> buy_sell(prices.size(), 0);
//    buy
    vector<int> buy(prices.size(), 0);
    int buy_val = prices[0];

    for (int i = 1; i < prices.size(); ++i) {
        buy_sell[i] = max(buy_sell[i - 1], prices[i] - buy_val - fee + buy[i - 1]);
        if (buy[i - 1] - buy_val < buy_sell[i - 1] - prices[i]) {
            buy[i] = buy_sell[i - 1];
            buy_val = prices[i];
        } else {
            buy[i] = buy[i - 1];
        }
    }

    return buy_sell.back();
}

int maxProfit_2(vector<int> &prices, int fee) {
    int n = prices.size();
    if (n < 2) return 0;
    int dp[n][2];
    memset(dp, 0, sizeof dp);
    dp[0][0] = -prices[0];
    dp[0][1] = 0;
    for (int i = 1; i < n; i++) {
        //cout << i;
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
        dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i] - fee);
    }
    return dp[n - 1][1];
}

int maxProfit_3(vector<int> &prices, int fee) {
    int n = prices.size();
    if (n < 2) return 0;
    int hold = -prices[0];
    int sell = 0;
    for (int i = 1; i < n; i++) {
        hold = max(hold, sell - prices[i]);
        sell = max(sell, hold + prices[i] - fee);
    }
    return sell;
}

// https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/solution/ti-hao-122mei-you-shou-xu-fei-jia-yi-dian-dong-xi-/
int maxProfit_4(vector<int> &prices, int fee) {
    if (prices.size() < 2)
        return 0;
    int ans = 0;

    int in_hand = prices[0];
    for (int i = 1; i < prices.size(); i++) {
        if (prices[i] < in_hand)
            in_hand = prices[i];

        else if (prices[i] - fee > in_hand) {
            ans += (prices[i] - fee) - in_hand;
            in_hand = prices[i] - fee;
        }
    }
    return ans;
}


int main() {
    cout << maxProfit({1, 3, 2, 8, 4, 9}, 2);
    cout << maxProfit({1, 3, 2, 2, 4, 3}, 2);
    cout << maxProfit({1, 4, 6, 2, 8, 3, 10, 14}, 3);
}