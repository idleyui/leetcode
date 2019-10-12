#include "alg.h"

void sortColors(vector<int> &nums) {
    int cur = 0, one = 0, two = nums.size() - 1;
    for (; two >= 0 && nums[two] == 2; two--);
    while (cur <= two) {
//        print_container(nums);
        if (nums[cur] == 0) {
            swap(nums[one], nums[cur]);
            one += 1;
            cur += 1;
        } else if (nums[cur] == 2) {
            swap(nums[two], nums[cur]);
            two -= 1;
        } else {
            cur += 1;
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