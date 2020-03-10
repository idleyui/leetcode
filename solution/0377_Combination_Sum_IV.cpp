#include "alg.h"

int dfs(vector<int> &nums, vector<int> &dp, int i, int target) {
    if (target < 0) return 0;
    if (target == 0) return 1;
    if (dp[target] >= 0) return dp[target];
    int num = 0;
    for (int j = 0; j < nums.size(); j++) {
        num += dfs(nums, dp, j, target - nums[j]);
    }
    dp[target] = num;
    return dp[target];
}

int combinationSum4(vector<int> &nums, int target) {
    vector<int> dp(target + 1, -1);
    return dfs(nums, dp, 0, target);
}

int main() {

}