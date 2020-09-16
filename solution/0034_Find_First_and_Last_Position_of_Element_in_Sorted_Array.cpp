#include "alg.h"

int search(vector<int> &nums, int target) {
    int l = 0, r = nums.size();
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (nums[mid] >= target) r = mid;
        else l = mid + 1;
    }
    return l;
}

vector<int> searchRange(vector<int> &nums, int target) {
    if (nums.empty()) return {-1, -1};
    int left = search(nums, target);
    if (left == nums.size() || nums[left] != target) return {-1, -1};
    int right = search(nums, target + 1);
    return {left, right - 1};
}

int main() {

}