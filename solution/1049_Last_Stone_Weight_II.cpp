#include "alg.h"

int lastStoneWeightII(vector<int> &stones) {
    int sum = accumulate(stones.begin(), stones.end(), 0), MAX = sum / 2;
    vector<vector<int>> dp(stones.size(), vector<int>(MAX + 1, 0));

    for (int w = 1; w <= MAX; w++) {
        if (stones[0] <= w) dp[0][w] = stones[0];
    }

    for (int i = 1; i < stones.size(); i++) {
        for (int w = 1; w <= MAX; w++) {
            if (stones[i] > w) {
                dp[i][w] = dp[max(0, i - 1)][w];
                continue;
            }
            dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - stones[i]] + stones[i]);
        }
    }
    return sum - dp.back().back() * 2;
}

int lastStoneWeightII_2(vector<int> &stones) {
    int sum = accumulate(stones.begin(), stones.end(), 0), MAX = sum / 2;
    vector<int> dp(MAX + 1, 0);

    for (int w = 1; w <= MAX; w++) {
        if (stones[0] <= w) dp[0][w] = stones[0];
    }

    for (int i = 1; i < stones.size(); i++) {
        for (int w = MAX; w > 0; w--) {
            if (stones[i] > w) break;
            dp[w] = max(dp[w], dp[w - stones[i]] + stones[i]);
        }
    }
    return sum-dp.back()*2;
}

int main() {

}