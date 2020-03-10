#include "alg.h"

int removeElement(vector<int> &nums, int val) {
    if (nums.size() < 1) return nums.size();
    int pos = 0;
    for (int i = 0; i < nums.size(); ++i)
        if (nums[i] != val)nums[pos++] = nums[i];
    return pos;
}

int main() {
    vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    vector<int> nums1 = {0};
    vector<int> nums2 = {};
    cout << removeElement(nums, 0) << endl;
    cout << removeElement(nums1, 0) << endl;
    cout << removeElement(nums2, 1) << endl;
    print_container(nums);
    print_container(nums1);
    print_container(nums2);
}