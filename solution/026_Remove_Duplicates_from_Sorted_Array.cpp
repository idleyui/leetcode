#include "alg.h"

int removeDuplicates(vector<int> &nums) {
    if (nums.size() == 0)return 0;
    int dup_index = 0, free = 0, last = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
        if (nums[i] == last) {
            last = nums[i];
            dup_index = dup_index == 0 ? i : dup_index;
            free++;
        } else if (free != 0) {
            last = nums[i];
            swap(nums[i], nums[dup_index++]);
        } else {
            last = nums[i];
        }
    }
    return nums.size() - free;
}

int removeDuplicates1(vector<int> &nums) {
    if (nums.size() < 2) return nums.size();
    int dup = 1;
    for (int i = 1; i < nums.size(); ++i)
        if (nums[i] != nums[i - 1]) nums[dup++] = nums[i];
    return dup;
}

int main() {
    vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    vector<int> nums1 = {0, 2, 2};
    vector<int> nums2 = {};
    cout << removeDuplicates(nums) << endl;
    cout << removeDuplicates(nums1) << endl;
    cout << removeDuplicates(nums2) << endl;
    print_container(nums);
    print_container(nums1);
    print_container(nums2);
}