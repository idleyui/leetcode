#include "alg.h"

int findComplement_1(int num) {
    int mask = 0, tmp = num;
    while (tmp > 0) {
        mask = (mask << 1) | 1;
        tmp >>= 1;
    }
    return (~num) & mask;
}

// https://leetcode.com/problems/number-complement/discuss/96017/3-line-C%2B%2B
int findComplement_2(int num) {
    int mask = -1;
    while (mask & num) mask <<= 1;
    return (~mask) & (~num);
}

int main() {

}