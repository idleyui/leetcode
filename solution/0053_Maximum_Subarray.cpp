#include "alg.h"

// Solution 1: simple iterative
// https://leetcode.com/problems/maximum-subarray/discuss/20189/Simplest-and-fastest-O(n)-C%2B%2B-solution
int maxSubArray(vector<int> &nums) {
    int accu = 0, max_val = INT_MIN;
    for (int num: nums) {
        accu = max(0, accu) + num;
        max_val = max(max_val, accu);
    }
    return max_val;
}

// Solution 2: divide and conquer


int main() {

}