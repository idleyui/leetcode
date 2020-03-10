#include "alg.h"

// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/discuss/48493/Compact-and-clean-C%2B%2B-solution
// You use while (start <= end) if you are returning the match from inside the loop.
// You use while (start < end) if you want to exit out of the loop first, and then use the result of start or end to return the match.
int findMin(vector<int> &nums) {
    int low = 0, high = nums.size() - 1;
    while (low < high) {
        int mid = (low + high) / 2;
        // low point in right half
        if (nums[low] < nums[high]) break;
        if (nums[mid] >= nums[low]) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    return nums[low];
}

// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/discuss/48484/A-concise-solution-with-proof-in-the-comment
// think as min in the left/right part
int findMin2(vector<int> &nums) {
    int low = 0, high = nums.size() - 1;
    while (low < high) {
        int mid = (low + high) / 2;
        if (nums[mid] < nums[high]) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    return nums[low];
}

int main() {

}