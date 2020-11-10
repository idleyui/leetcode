#include "alg.h"

int firstMissingPositive(vector<int> &nums) {
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