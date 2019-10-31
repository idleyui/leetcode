#include "alg.h"

int lengthOfLIS(vector<int> &nums) {
    if (nums.empty()) return 0;
    vector<int> dp(nums.size(), 0);
    dp[0] = 1;
    int max_val = 1;
    for (int i = 1; i < nums.size(); i++) {
        int max_left = 0;
        for (int j = i - 1; j >= 0; j--) {
            if (nums[j] < nums[i]) max_left = max(max_left, dp[j]);
        }
        dp[i] = max_left + 1;
        max_val = max(max_val, dp[i]);
    }
    return max_val;
}

int main() {

}