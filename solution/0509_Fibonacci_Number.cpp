#include "alg.h"

int fib(int N) {
    int one = 0, two = 1;
    for (int i = 0; i < N; i++) {
        int sum = one + two;
        one = two;
        two = sum;
    }
    return one;
}

int main() {
}