#include "alg.h"

// https://leetcode.com/problems/powx-n/discuss/19544/5-different-choices-when-talk-with-interviewers
double myPow(double x, int n) {
    if (n == 0) return 1;
    if (n < 0) return 1 / x * myPow(1 / x, -(n + 1));
    double val = myPow(x, n / 2);
    if (n % 2 == 0) return val * val;
    return val * val * x;
}

// iterative
double myPow_2(double x, int n) {
    if (n == 0) return 1;
    if (n < 0) return 1 / x * myPow_2(1 / x, -(n + 1));
    double ans = 1;
    while (n > 0) {
        if (n & 1) ans *= x;
        x *= x;
        n >>= 1;
    }
    return ans;
}

// bit operation //todo
// https://leetcode.com/problems/powx-n/discuss/19571/My-answer-using-bit-operation-(C%2B%2B-implementation)

int main() {

}