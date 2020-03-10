#include "alg.h"

double myPow(double x, int n, unordered_map<int, double> &n2val) {
    if (n2val.count(n)) return n2val[n];
    double val = myPow(x, n / 2, n2val) * myPow(x, n / 2, n2val) * (n % 2 == 0 ? 1 : x);
    n2val[n] = val;
    return val;
}

double myPow(double x, int n) {
    if (x == 1) return 1;
    unordered_map<int, double> n2val = {{0, 1}};
    double val = myPow(x, n, n2val);
    return n >= 0 ? val : 1 / val;
}

int main() {

}