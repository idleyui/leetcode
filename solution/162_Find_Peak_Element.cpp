#include "alg.h"

//https://leetcode.com/problems/find-peak-element/discuss/50232/Find-the-maximum-by-binary-search-(recursion-and-iteration)/50717
int findPeakElement(vector<int> &nums) {
    int low = 0, high = nums.size() - 1;
    while (low < high) {

        int mid = (low + high) / 2;
        int mid1 = mid + 1;
        if (nums[mid] > nums[mid1]) {
            high = mid;
        } else {
            low = mid1;
        }
    }
    return low;
}

int main() {

}