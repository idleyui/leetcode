#include "alg.h"

// binary search
int arrangeCoins_1(int n) {
    if (n < 2) return n;
    long l = 1, h = n, mid = 0;
    while (l < h) {
        mid = l + (h - l) / 2;
        long long sum = (1 + mid) * mid / 2;
        if (sum == n) return mid;
        else if (sum < n) l = mid + 1;
        else h = mid;
    }
    return l - 1;
}

// math
// https://leetcode.com/problems/arranging-coins/discuss/92365/C%2B%2B-1-line-code
int arrangeCoins_2(int n) {
    return sqrt(2.0 * n + 0.25) - 0.5;
}

int main() {

}