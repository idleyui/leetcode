#include "alg.h"

int search(vector<int> &nums, int target, bool left) {
    int low = 0, high = nums.size() - 1, pos = -1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (nums[mid] == target) {
            pos = mid;
            if (left) high = mid - 1;
            else low = mid + 1;
        } else if (nums[mid] > target) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return pos;
}

vector<int> searchRange(vector<int> &nums, int target) {
    return {search(nums, target, true),
            search(nums, target, false)};
}

int search(vector<int> &nums, int target) {
    int l = 0, h = nums.size();
    while (l < h) {
        int mid = (l + h) / 2;
        if (nums[mid] < target) l = mid + 1;
        else h = mid;
    }
    return h;
}

vector<int> searchRange1(vector<int> &nums, int target) {
    if (nums.empty()) return {-1, -1};
    int left = search(nums, target);
    int right = search(nums, target + 1);
    if (left == nums.size() || nums[left] != target) return {-1, -1};
    return {left, right - 1};
}

int main() {

}