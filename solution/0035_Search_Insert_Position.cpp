#include "alg.h"

int searchInsert(vector<int> &nums, int target) {
    if (!nums.empty() && target > nums.back()) return nums.size();
    int l = 0, r = nums.size() - 1;
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (nums[mid] < target) l = mid + 1;
        else r = mid;
    }
    return l;
}


int searchInsert_2(vector<int> &nums, int target) {
    if (nums.empty()) return 0;
    int l = 0, r = nums.size() - 1;
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (nums[mid] < target) l = mid + 1;
        else r = mid;
    }
    return nums[l] >= target ? l : nums.size();
}

int searchInsert_3(vector<int> &nums, int target) {
    int l = 0, r = nums.size();
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (nums[mid] >= target) r = mid;
        else l = mid + 1;
    }
    return l;
}


int main() {

}