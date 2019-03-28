#include "alg.h"

int main() {
    char c = -1;
    unsigned b = c;
//    cout << b;
    long rt = 1, i = 2;
    for (; i < 100 && rt > 0; ++i) {
        rt *= i;
    }
    cout << i - 1;
}