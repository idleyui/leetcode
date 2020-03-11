#include "alg.h"


bool isBadVersion(int version);

// note: use l + (h-l) / 2 instead of (l+h)/2
// https://leetcode.com/problems/first-bad-version/discuss/71311/A-good-warning-to-me-to-use-start%2B(end-start)2-to-avoid-overflow
int firstBadVersion(int n) {
    int l = 1, h = n;
    while (l < h) {
        int mid = l + (h - l) / 2;
        if (isBadVersion(mid)) {
            h = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
}

int main() {

}