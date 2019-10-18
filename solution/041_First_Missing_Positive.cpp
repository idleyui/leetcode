#include "alg.h"

int firstMissingPositive(vector<int> &nums) {
    int min = INT_MAX, max = -1;
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] > 0 && nums[i] > max) max = nums[i];
        if (nums[i] > 0 && nums[i] < min) min = nums[i];
    }
    if (min != 1) return 1;
    for (int i = 0; i < nums.size();) {
        if (nums[i] <= 0 || nums[i] > nums.size() || nums[nums[i] - 1] == nums[i]) i++;
        else swap(nums[nums[i] - 1], nums[i]);
    }
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] != i + 1)return i + 1;
    }
    return nums.size() + 1;
}

int main() {

}