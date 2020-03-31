#include "alg.h"
//https://www.lintcode.com/problem/wiggle-sort/description
//https://www.cnblogs.com/grandyang/p/5500067.html

void wiggleSort_1(vector<int> &nums) {
    // write your code here
    for (int i = 1; i < nums.size(); i++) {
        int num = nums[i], rightmost = nums[i - 1];
//        i % 2 is slow, use up and !up
        if (i % 2 == 1 && num < rightmost || i % 2 == 0 && num > rightmost) {
            swap(nums[i - 1], nums[i]);
        }
    }
}

void wiggleSort_2(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    for (int i = 1; i < nums.size(); i++) {
        if (i % 2 == 0) swap(nums[i - 1], nums[i]);
    }
}

int main() {

}