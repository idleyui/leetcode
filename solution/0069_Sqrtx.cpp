#include "alg.h"

int mySqrt(int x) {
    if (x == 0) return 0;
    if (x == 1) return 1;
    int low = 0, high = x;
    while (low <= high) {
        int mid = (low + high) / 2;
        int div = x / mid;
        if (div > mid) {
            low = mid + 1;
        } else if (div < mid) {
            high = mid - 1;
        } else {
            return mid;
        }
    }
    return high;
}

int main() {
    for (int i = 0; i < 101; i++)
        cout << mySqrt(i) << ',';
}