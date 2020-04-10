#include "alg.h"

int fib(int N) {
    int one = 0;
    int two = 1;
    if (N == 0) return one;
    if (N == 1) return two;
    for (int i = 2; i <= N; i++) {
        int tmp = two;
        two = one + two;
        one = tmp;
    }
    return two;
}

int main() {

}