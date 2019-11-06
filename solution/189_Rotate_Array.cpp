#include "alg.h"

void rotate_with_buf(vector<int> &nums, int k) {
    k = k % nums.size();
    vector<int> copy;
    copy.reserve(k);
    for (int i = nums.size() - k; i < nums.size(); i++) {
        copy.push_back(nums[i]);
    }

    for (int i = nums.size() - k - 1; i >= 0; i--) {
        nums[i + k] = nums[i];
    }

    for (int i = 0; i < k; i++) {
        nums[i] = copy[i];
    }
}

//https://leetcode.com/problems/rotate-array/discuss/54277/Summary-of-C%2B%2B-solutions
//todo

int main() {

}