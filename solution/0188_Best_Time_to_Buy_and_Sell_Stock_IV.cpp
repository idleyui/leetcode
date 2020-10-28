#include "alg.h"

int maxProfit(int k, vector<int> &prices) {
    int n = prices.size();

    if (k >= n / 2) {
        int profit = 0;
        for (int i = 1; i < n; i++) {
            profit += max(0, prices[i] - prices[i - 1]);
        }
        return profit;
    }

    int cost[k + 1], profit[k + 1];
    memset(cost, 0x7f, sizeof(cost));
    memset(profit, 0, sizeof(profit));
    // for(int i = 0; i <= k; i++) {
    //     cost[i] = INT_MAX;
    //     profit[i] = 0;
    // }
    for (int j = 0; j < n; j++) {
        auto p = prices[j];
        for (int i = 1; i <= k; i++) {
            cost[i] = min(cost[i], p - profit[i - 1]);
            profit[i] = max(profit[i], p - cost[i]);
        }
    }
    return profit[k];
}

int main() {
    cout << maxProfit(2, {3, 2, 6, 5, 0, 3});
}