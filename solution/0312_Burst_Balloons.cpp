#include "alg.h"

//https://leetcode.com/problems/burst-balloons/discuss/76245/Easiest-Java-Solution
int maxCoins(vector<int> &nums, int low, int high, vector<vector<int>> &dp) {
    if (high < low) return 0;
    if (dp[low][high] >= 0) return dp[low][high];
    int max_coin = nums[low];


    for (int i = low; i <= high; i++) {
        int left = maxCoins(nums, low, i - 1, dp);
        int right = maxCoins(nums, i + 1, high, dp);
        int coin = nums[i] * (low > 0 ? nums[low - 1] : 1) * (high < nums.size() - 1 ? nums[high + 1] : 1);
        max_coin = max(max_coin, coin + left + right);
        // cout << max_coin << ",";
    }
    dp[low][high] = max_coin;
    return dp[low][high];
}

int maxCoins(vector<int> &nums) {
    vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), -1));
    return maxCoins(nums, 0, nums.size() - 1, dp);
}

int main() {

}