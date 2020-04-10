#include "alg.h"

bool checkPerfectNumber(int num) {
    if (num == 1) return false;
    int sum = 1;
    for (int l = 2, r = num; l < r; l++) {
        if (num % l == 0) {
            sum += l;
            sum += (num / l);
            r = num / l;
        }
    }
    return sum == num;
}

int main() {

}