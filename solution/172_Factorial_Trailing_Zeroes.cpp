#include "alg.h"
// #overflow    #math

int trailingZeroes(int n) {
    int zeroes = 0;
    for (long long five = 5; five < n; five *= 5) {
        zeroes += n / five;
    }
    return zeroes;
}

int main() {

}
