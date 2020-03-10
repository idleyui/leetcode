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

int main() {
    cout << maxProfit({1, 3, 2, 8, 4, 9}, 2);
    cout << maxProfit({1, 3, 2, 2, 4, 3}, 2);
    cout << maxProfit({1, 4, 6, 2, 8, 3, 10, 14}, 3);
}