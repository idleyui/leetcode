#include "alg.h"

// binary search
bool isPerfectSquare_1(int num) {
    long l = 1, h = num, mid = 0;
    while (l <= h) {
        mid = l + (h - l) / 2;
        long v = mid * mid;
        if (v == num) return true;
        else if (v < num) l = mid + 1;
        else h = mid - 1;
    }
    return false;
}

// newton method
bool isPerfectSquare_2(int num) {
    long x = num;
    while (x * x > num) {
        x = (x + num / x) / 2;
    }
    return x * x == num;
}

int main() {

}