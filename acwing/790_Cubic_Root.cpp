// https://www.acwing.com/problem/content/792/
#include <cstdio>

using namespace std;

double N;

double cubic_root(double n) {
    double l = 0, h = n;
    while(true) {
        double mid = l + (h-l)/2;
        double diff = mid * mid * mid - n;
        double abs_diff = diff > 0?diff:-diff;
        if (abs_diff < 0.0000001) return mid;
        else if (diff > 0) h = mid;
        else l = mid;
    }
    return 0;
}

int main() {
    scanf("%lf", &N);
    double val = cubic_root(N>0?N:-N);
    printf("%.6f", N>0?val:-val);
}
