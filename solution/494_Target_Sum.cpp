#include "alg.h"

int findTargetSumWays(vector<int> &nums, int S) {
    if (S > 1000 || S < -1000) return 0;
    vector<vector<int>> dp(nums.size(), vector<int>(2001, 0));
    dp[0][1000 + nums[0]] += 1;
    dp[0][1000 - nums[0]] += 1;
    for (int i = 1; i < nums.size(); i++) {
        for (int j = 0; j < 2001; j++) {
            dp[i][j] = (j - nums[i] < 0 ? 0 : dp[i - 1][j - nums[i]]) +
                       (j + nums[i] > 2000 ? 0 : dp[i - 1][j + nums[i]]);
        }
    }
    return dp.back()[1000 + S];
}

int main() {

}