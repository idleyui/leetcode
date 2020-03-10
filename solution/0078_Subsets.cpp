#include "alg.h"


// Solution 1: backtrack
void backtrack(vector<vector<int>> &result, vector<int> tmp, vector<int> &nums, int start) {
    result.push_back(tmp);
    for (int i = start; i < nums.size(); i++) {
        tmp.push_back(nums[i]);
        backtrack(result, tmp, nums, i + 1);
        tmp.pop_back();
    }
}

vector<vector<int>> subsets1(vector<int> &nums) {
    vector<vector<int>> result;
    backtrack(result, {}, nums, 0);
    return result;
}


// Solution 1: iterative
vector<vector<int>> subsets2(vector<int> &nums) {
    vector<vector<int>> result = {{}};
    for (int num: nums) {
        int n = result.size();
        for (int i = 0; i < n; i++) {
            vector<int> tmp = result[i];
            tmp.push_back(num);
            result.push_back(tmp);
        }
    }
    return result;
}

// Solution 3: bitwise
//https://leetcode.com/problems/subsets/discuss/507813/Simple-way-to-understand-why-time-complexity-is-O(N-2N)
//https://leetcode.com/problems/subsets/discuss/506830/C%2B%2B-solution-with-bit-operation
vector<vector<int>> subsets3(vector<int> &nums) {
    int n = 1 << nums.size();
    vector<vector<int>> result;
    for (unsigned int i = 0; i < n; i++) {
        vector<int> tmp;
        for (int num: nums) {
            if (i & 1) { tmp.push_back(num); }
            i >>= 1;
        }
        result.push_back(tmp);
    }
    return result;
}

int main() {
//    vector<int> nums = {1, 2, 3};
    vector<int> nums = {1};
    for (const auto &subset: subsets1(nums)) {
        print_container(subset);
    }
}