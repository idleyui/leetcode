// [good question]
#include "alg.h"

// todo discuss
string convertToTitle_1(int n) {
    string s;
    while (n > 0) {
        if (n % 26 == 0) {
            s = 'Z' + s;
            n /= 26;
            n -= 1;
        } else {
            s = (char) ('A' + n % 26 - 1) + s;
            n /= 26;
        }
    }
    return s;
}


// https://leetcode.com/problems/excel-sheet-column-title/discuss/51399/Accepted-Java-solution
string convertToTitle_2(int n) {
    string s;
    while (n > 0) {
        n--;
        s = (char) ('A' + n % 26) + s;
        n /= 26;
    }
    return s;
}

int main() {
}