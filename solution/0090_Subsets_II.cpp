#include "alg.h"

// Solution 1: backtrack
// https://leetcode.com/problems/subsets-ii/discuss/30164/Accepted-10ms-c%2B%2B-solution-use-backtracking-only-10-lines-easy-understand.
void backtrack(vector<vector<int>> &result, vector<int> tmp, vector<int> &nums, int begin) {
    result.push_back(tmp);
    if (begin >= nums.size()) return;
    for (int i = begin; i < nums.size(); i++) {
        if (i > begin && nums[i] == nums[i - 1]) continue;
        tmp.push_back(nums[i]);
        backtrack(result, tmp, nums, i + 1);
        tmp.pop_back();
    }
}

vector<vector<int>> subsetsWithDup1(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> result = {};
    backtrack(result, {}, nums, 0);
    return result;
}

void backtrace(vector<vector<int>> &result, vector<int> &tmp, vector<int> &nums, int begin) {
    if (begin >= nums.size()) {
        result.push_back(tmp);
        return;
    }

    tmp.push_back(nums[begin]);
    backtrace(result, tmp, nums, begin + 1);
    tmp.pop_back();

    int begin_val = nums[begin];
    for (begin = begin + 1; begin < nums.size() && nums[begin] == begin_val; begin++);
    backtrace(result, tmp, nums, begin);
}

// bit thought
vector<vector<int>> subsetsWithDup(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> result;
    vector<int> tmp;
    backtrace(result, tmp, nums, 0);
    return result;
}

// Solution 2: iterative
// https://leetcode.com/problems/subsets-ii/discuss/30137/Simple-iterative-solution
vector<vector<int>> subsetsWithDup2(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> result = {{}};
    int startIdx = 0;
    for (int j = 0; j < nums.size(); j++) {
        int n = result.size();
        if (j > 0 && nums[j] != nums[j - 1]) startIdx = 0;
        for (int i = startIdx; i < n; i++) {
            auto tmp = result[i];
            tmp.push_back(nums[j]);
            result.push_back(tmp);
        }
        startIdx = n;
    }
    return result;
}

int main() {

}