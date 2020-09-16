#include "alg.h"

bool search(vector<int> &nums, int target) {
    int n = nums.size(), l = 0, r = n - 1;
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (nums[mid] == nums[r]) {
            if (nums[r] >= nums[r - 1])r--;
            else {
                l = r;
                break;
            }
        } else if (nums[mid] > nums[r]) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }

    if (target <= nums[n - 1]) { r = n - 1; }
    else {
        r = l - 1;
        l = 0;
    }

    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (nums[mid] == target) return true;
        else if (nums[mid] < target) l++;
        else r--;
    }
    return false;
}

int main() {

}