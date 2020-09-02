#include "alg.h"

// Solution 1: naive dp
int climbStairs1(int n) {
    if (n == 1) return 1;
    vector<int> dp(n, 0);
    dp[0] = 1;
    dp[1] = 2;
    for (int i = 2; i < n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n - 1];
}

// Solution 2: only 2 buffer needed
// https://leetcode.com/problems/climbing-stairs/discuss/25299/Basically-it's-a-fibonacci.
int climbStairs2(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;

    int one_step_before = 2;
    int two_step_before = 1;
    int last = 0;

    for (int i = 2; i < n; i++) {
        last = one_step_before + two_step_before;
        two_step_before = one_step_before;
        one_step_before = last;
    }
    return last;
}

// wo tai nb le, no last buffer needed
int climbStarts3(int n){
    if (n == 1) return 1;
    int one = 1, two = 2;

    for(int i = 2; i < n; i++){
        one = one + two;
        swap(one, two);
    }
    return two;
}

int climbStarts_4(int n) {
    int one = 1, two = 1;
    for(int i = 0; i < n; i++) {
        int sum = one + two;
        one = two;
        two = sum;
    }
    return one;
}

int main() {

}