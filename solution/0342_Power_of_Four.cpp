#include "alg.h"

bool isPowerOfFour(int num) {
    for (int i = 2; i < 31; i += 2) {
        if (num & (1 << i)) return true;
    }
    return false;
}

// https://leetcode.com/problems/power-of-four/discuss/80457/Java-1-line-(cheating-for-the-purpose-of-not-using-loops)
bool isPowerOfFour_2(int num) {
    return num > 0 && (num & (num - 1)) == 0 && (num & 0x55555555) != 0;
}

int main() {

}