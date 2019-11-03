#include "alg.h"

bool search(vector<int> &nums, vector<unordered_set<int>> &dp, int begin, int sum) {
    if (begin >= nums.size() || dp[begin].count(sum)) return false;
    if (sum == 0) return true;
    // cout << begin << ',' << sum << endl;
    for (int i = begin; i < nums.size(); i++) {
        bool next = search(nums, dp, i + 1, sum - nums[i]);
        if (next) return true;
    }
    dp[begin].insert(sum);
    return false;
}

bool canPartition(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    int sum = 0;
    for (int i: nums) sum += i;
    if (sum % 2 != 0) return false;
    sum = sum / 2;

    vector<unordered_set<int>> dp(nums.size(), unordered_set<int>());
    return search(nums, dp, 0, sum);
}

int main() {
}