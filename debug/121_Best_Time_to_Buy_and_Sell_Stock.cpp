#include "alg.h"

int maxProfit(vector<int> &prices) {
    if (prices.size() < 2) return 0;
    int max = INT_MIN, min = prices[0];
    for (int i = 1; i < prices.size(); i++) {
        int max_today = prices[i] - min;
        if (max_today > max) max = max_today;
        if (prices[i] < min) min = prices[i];
    }
    return max > 0 ? max : 0;
}

int main() {

}