#include "alg.h"

// Solution 1: backtrack
// https://leetcode.com/problems/permutations-ii/discuss/18596/A-simple-C%2B%2B-solution-in-only-20-lines
void backtrack(vector<vector<int>> &result, vector<int> nums, int begin) {
    if (nums.size() == begin) {
        result.push_back(nums);
        return;
    }
    for (int i = begin; i < nums.size(); i++) {
        if (i > begin && nums[i] == nums[begin]) continue;
        swap(nums[i], nums[begin]);
        backtrack(result, nums, begin + 1);
    }
}

vector<vector<int>> permuteUnique(vector<int> &nums) {
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());
    backtrack(result, nums, 0);
    return result;
}

int main() {

}