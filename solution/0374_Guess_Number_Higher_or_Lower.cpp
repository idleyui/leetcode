#include "alg.h"

int guess(int);

int guessNumber(int n) {
    int l = 1, h = n;
    while (l <= h) {
        int mid = l + (h - l) / 2;
        if (guess(mid) == 0) { return mid; }
        else if (guess(mid) < 0) { h = mid - 1; }
        else { l = mid + 1; }
    }
    return 0;
}

int main() {

}