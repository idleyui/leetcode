#include "alg.h"

int wiggle(vector<int> &nums, bool up) {
    int cnt = 0;
    int base = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
        if (up && nums[i] > base || !up && nums[i] < base) {
            up = !up;
            cnt++;
        }
        base = nums[i];
    }
    return cnt + 1;
}

int wiggleMaxLength(vector<int> nums) {
    return max(wiggle(nums, true), wiggle(nums, false));
}

int main() {
    cout << wiggleMaxLength({1, 7, 4, 9, 2, 5}) << endl;
    cout << wiggleMaxLength({1, 17, 5, 10, 13, 15, 10, 5, 16, 8}) << endl;
    cout << wiggleMaxLength({1, 2, 3, 4, 5, 6, 7, 8, 9}) << endl;
}