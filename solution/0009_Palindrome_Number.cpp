#include "alg.h"

bool isPalindrome(int x) {
    if (x < 0 || (x > 0 && x % 10 == 0)) return false;
    int sum = 0;
    while (x > sum) {
        sum = sum * 10 + x % 10;
        x /= 10;
    }
    return (x == sum) || (x == sum / 10);
}

bool isPalindrome_2(int x) {
    if (x < 0) return false;
    long r = 0, tmp = x;
    while (x) {
        r = r * 10 + x % 10;
        x /= 10;
    }
    return tmp == r;
}

int main() {

}