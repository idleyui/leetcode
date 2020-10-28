#include "alg.h"

int maxProfit_2(vector<int> &prices) {
    int profit = 0, buy, sell, i = 0;
    while (i < prices.size()) {
        for (; i < prices.size() - 1 && prices[i] >= prices[i + 1]; i++);
        buy = i;
        if (buy == prices.size() - 1) break;
        for (; i < prices.size() - 1 && prices[i] <= prices[i + 1]; i++);
        sell = i;
        profit += (prices[sell] - prices[buy]);
    }
    return profit;
}

int maxProfit(vector<int> &prices) {
    int max_val = 0;
    for (int i = 1; i < prices.size(); i++) {
        max_val += max(0, prices[i] - prices[i - 1]);
    }
    return max_val;
}

int main() {

}