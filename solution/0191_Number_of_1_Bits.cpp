#include "alg.h"

// solution 1: right shift
int hammingWeight(uint32_t n) {
    int cnt = 0;
    while (n) {
        cnt += n & 1;
        n >>= 1;
    }
    return cnt;
}

// solution 2: left shift
int hammingWeight_2(uint32_t n) {
    int cnt = 0;
    uint32_t mask = 1;
    while (mask) {
        if (n & mask) cnt++;
        mask <<= 1;
    }
    return cnt;
}

// use (n & n-1) remove right most 1
int hammingWeight_3(uint32_t n) {
    int cnt = 0;
    while (n) {
        n &= n - 1;
        cnt++;
    }
    return cnt;
}

// other: https://en.wikipedia.org/wiki/Hamming_weight

int main() {

}