#include "alg.h"

int subarraySum(vector<int> &nums, int k) {
    vector<int> dp1(nums.size(), 0);
    vector<int> dp2(nums.size(), 0);
    int cnt = 0;
    for (int i = 0; i < nums.size(); i++) {
        dp1[i] = nums[i];
        if (nums[i] == k) cnt++;
    }
    for (int len = 2; len <= nums.size(); len++) {
        for (int i = 0; i < nums.size() - len + 1; i++) {
            dp2[i + len - 1] = dp1[i + len - 2] + nums[i + len - 1];
            if (dp2[i + len - 1] == k) cnt++;
        }
        swap(dp1, dp2);
    }
    return cnt;
}

int main() {
}