#include "alg.h"

int maxProfit(vector<int> &prices) {
    if (prices.size() < 2) return 0;
    int max_val = 0;
    for (int i = 1; i < prices.size(); i++) {
        max_val += max(0, prices[i] - prices[i - 1]);
    }
    return max_val;
}

int main() {

}