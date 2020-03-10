#include "alg.h"

// Solution 1: use prev min price
int maxProfit1(vector<int> &prices) {
    if (prices.size() < 2) return 0;
    int max_profit = 0, min_price = prices[0];
    for (int num: prices) {
        max_profit = max(max_profit, num - min_price);
        min_price = min(min_price, num);
    }
    return max_profit;
}

// Solution 2: transfer to 53.Maximum Subarray
int maxProfit2(vector<int> &prices) {
    if (prices.size() < 2) return 0;
    vector<int> diff(prices.size() - 1, 0);
    for (int i = 1; i < prices.size(); i++) {
        diff[i - 1] = prices[i] - prices[i - 1];
    }

    int max_sum = INT_MIN, accu = 0;
    for (int num: diff) {
        accu = max(0, accu + num);
        max_sum = max(max_sum, accu);
    }
    return max_sum;
}

int main() {

}