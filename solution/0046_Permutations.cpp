#include "alg.h"

// Solution 1: backtrack
void backtrack1(vector<vector<int>> &result, vector<int> tmp, vector<int> &nums) {
    if (tmp.size() == nums.size()) result.push_back(tmp);
    else {
        for (int i = 0; i < nums.size(); i++) {
            if (find(tmp.begin(), tmp.end(), nums[i]) != tmp.end()) continue;
            tmp.push_back(nums[i]);
            backtrack1(result, tmp, nums);
            tmp.pop_back();
        }
    }
}

vector<vector<int>> permute1(vector<int> &nums) {
    vector<vector<int>> result = {};
    backtrack1(result, {}, nums);
    return result;
}

// Solution 2: better backtrack
// https://leetcode.com/problems/permutations/discuss/18247/My-elegant-recursive-C%2B%2B-solution-with-inline-explanation
void backtrack2(vector<vector<int>> &result, vector<int> &nums, int begin) {
    if (begin == nums.size()) {
        result.push_back(nums);
        return;
    }
    for (int i = begin; i < nums.size(); i++) {
        swap(nums[begin], nums[i]);
        backtrack2(result, nums, begin + 1);
        swap(nums[begin], nums[i]);
    }
}

vector<vector<int>> permute(vector<int> &nums) {
    vector<vector<int>> result;
    backtrack2(result, nums, 0);
    return result;
}


int main() {
//    vector<int> vv = {1, 2, 3};
    vector<int> vv = {};
    for (auto v: permute(vv)) {
        print_container(v);
    }
}