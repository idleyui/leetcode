#include "alg.h"

int maxProfit(vector<int> &prices) {
    if (prices.size() < 2) return 0;
    int dp[prices.size()] = {0};
    int max[2] = {INT_MIN, INT_MIN};
    int min = prices[0], tmp_max = 0;
    for (int i = 1; i < prices.size(); i++) {
        if (prices[i] > prices[i - 1]) {
            tmp_max = prices[i] - min;
        } else {
            if (max[0] < tmp_max) max[0] = tmp_max;
            if (max[0] > max[1]) swap(max[0], max[1]);
            min = prices[i];
            tmp_max = INT_MIN;
        }
    }
    if (prices[prices.size() - 1] > prices[prices.size() - 2]) {
        if (max[0] < tmp_max) max[0] = tmp_max;
        if (max[0] > max[1]) swap(max[0], max[1]);
    }
    return (max[0] > 0 ? max[0] : 0) + (max[1] > 0 ? max[1] : 0);
}

int main() {
//    vector<int> v = {3, 3, 5, 0, 0, 3, 1, 4};
//    vector<int> v2 = {1, 2, 3, 4, 5};
//    vector<int> v3 = {7, 6, 4, 3, 2};
    vector<int> v3 = {3,2,6,5,0,3};
//    cout << maxProfit(v);
//    cout << maxProfit(v2);
    cout << maxProfit(v3);
}