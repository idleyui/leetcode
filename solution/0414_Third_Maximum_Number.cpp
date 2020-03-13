#include "alg.h"

int thirdMax(vector<int> &nums) {
    if (nums.empty()) return 0;
    long first = LLONG_MIN, second = first, third = first;
    for (int i: nums) {
        if (i == first || i == second || i == third) continue;
        if (i > third) third = i;
        if (third > second) swap(second, third);
        if (second > first) swap(first, second);
    }
    return third == LLONG_MIN ? first : third;
}

// or set
// https://leetcode.com/problems/third-maximum-number/discuss/90209/Short-easy-C%2B%2B-using-set

int main() {

}