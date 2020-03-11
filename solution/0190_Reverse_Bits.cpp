#include "alg.h"

uint32_t reverseBits(uint32_t n) {
    uint32_t rt = 0;
    for (int i = 0; i < 32; i++) {
        uint32_t v = (n << 31 >> i);
        if (1 & n) {
            rt |= (1 << (31 - i));
        }
        n >>= 1;
    }
    return rt;
}

// https://leetcode.com/problems/reverse-bits/discuss/54741/O(1)-bit-operation-C%2B%2B-solution-(8ms)
uint32_t reverseBits_2(uint32_t n) {
    uint32_t rt = 0;
    rt = (n << 16) | (n >> 16);
    rt = ((rt & 0xff00ff00) >> 8) | ((rt & 0x00ff00ff) << 8);
    rt = ((rt & 0xf0f0f0f0) >> 4) | ((rt & 0x0f0f0f0f) << 4);
    rt = ((rt & 0xcccccccc) >> 2) | ((rt & 0x33333333) << 2);
    rt = ((rt & 0xaaaaaaaa) >> 1) | ((rt & 0x55555555) << 1);
    return rt;
}

int main() {

}