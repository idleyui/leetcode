#include "alg.h"

static int cnt(int a) {
    int ans = 0;
    while (a > 0) {
        ans += (a & 1);
        a >>= 1;
    }
    return ans;
}

static bool cmp(const int &a, const int &b) {
    int cnt1 = cnt(a);
    int cnt2 = cnt(b);
    return cnt1 < cnt2 || (cnt1 == cnt2 && a < b);
}

vector<int> sortByBits(vector<int> &arr) {
    sort(arr.begin(), arr.end(), cmp);
    return arr;
}

int main() {

}