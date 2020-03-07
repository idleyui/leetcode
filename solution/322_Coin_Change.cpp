#include "alg.h"

// Solution 1: iterative Dp
int coinChange1(vector<int> &coins, int amount) {
    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;
    //min_i = min{min_i-coins[0], min_i-coins[1], ...} + 1
    for (int i = 1; i <= amount; i++) {
        for (int j = 0; j < coins.size(); j++) {
            if (coins[j] <= i) {
                dp[i] = min(dp[i - coins[j]] + 1, dp[i]);
            }
        }
    }
    return dp[amount] > amount ? -1 : dp[amount];
}

// Solution 2: recursive Dp
// Do not use -1 < coins.size()
int helper(vector<int> &dp, vector<int> &coins, int amount) {
    if (amount < 0) return -1;
    if (amount == 0) return 0;
    if (dp[amount] < INT_MAX) return dp[amount];

    int min_step = INT_MAX;
    for (int coin: coins) {
        int step = helper(dp, coins, amount - coin);
        if (step < 0) continue;
        min_step = min(min_step, step + 1);
    }

    if (min_step == INT_MAX) min_step = -1;
    dp[amount] = min_step;
    return min_step;
}

int coinChange2(vector<int> &coins, int amount) {
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;
    return helper(dp, coins, amount);
}


int main() {

}