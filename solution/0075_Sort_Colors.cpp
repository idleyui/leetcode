#include "alg.h"

// Solution 1: Two-pass-counting
// too simple


// Solution 2: Two-Pointer
// https://leetcode.com/problems/sort-colors/discuss/26500/Four-different-solutions
void sortColors(vector<int> &nums) {
    int i = 0, zero = 0, two = nums.size() - 1;
//    for (; two >= 0 && nums[two] == 2; two--);
    while (i <= two) {
        if (nums[i] == 0) {
            swap(nums[zero], nums[i]);
            zero += 1;
            i += 1;
        } else if (nums[i] == 2) {
            swap(nums[two], nums[i]);
            two -= 1;
        } else {
            i += 1;
        }
    }
}

int main() {
    vector<vector<int>> tests = {
            {2, 0, 2, 1, 1, 0},
            {2, 1, 2, 1, 1, 1},
            {0, 1, 1, 1, 1, 1},
            {1, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0},
            {1, 1, 1, 1, 1},
            {2, 2, 2, 2, 2}
    };
    for (auto &nums: tests) {
        sortColors(nums);
        print_container(nums);
    }
}