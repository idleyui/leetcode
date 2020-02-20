#include "alg.h"

// Solution 1: simple iterative
// https://leetcode.com/problems/maximum-subarray/discuss/20189/Simplest-and-fastest-O(n)-C%2B%2B-solution
int maxSubArray(vector<int> &nums) {
    int accu = 0;
    int max_val = INT_MIN;
    for (int num: nums) {
        int sum = accu + num;
        if (sum < 0) accu = 0;
        else accu = sum;
        max_val = max(max_val, sum);
    }
    return max_val;
}

// Solution 2: divide and conquer


int main() {

}