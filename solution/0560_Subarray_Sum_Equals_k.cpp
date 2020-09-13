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

int subarraySum_2(vector<int> &nums, int k) {
    int n = nums.size(), cnt = 0;

    for (int i = 0; i < n; i++) {
        int base = 0;
        for (int j = i; j < n; j++) {
            base += nums[j];
            if (base == k) cnt++;
        }
    }
    return cnt;
}

// https://leetcode.com/problems/subarray-sum-equals-k/discuss/102106/Java-Solution-PreSum-%2B-HashMap
// https://leetcode.com/problems/subarray-sum-equals-k/discuss/190674/Python-O(n)-Based-on-%22running_sum%22-concept-of-%22Cracking-the-coding-interview%22-book
// sum[i...j] = sum[0...j]-sum[0...i]
int subarraySum_3(vector<int> &nums, int k) {
    int n = nums.size(), cnt = 0;
    unordered_map<int, int> sum2idx;
    sum2idx[0] = 1;

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += nums[i];
        if (sum2idx.count(sum - k)) {
            cnt += sum2idx[sum - k];
        }
        sum2idx[sum] += 1;
    }
    return cnt;
}

int main() {
}