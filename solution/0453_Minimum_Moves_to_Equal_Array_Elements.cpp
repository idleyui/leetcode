#include "alg.h"

int minMoves(vector<int> &nums) {
    int m = INT_MAX;
    for (int i: nums) { m = min(m, i); }

    int cnt = 0;
    for (int i: nums) { cnt += i - m; }

    return cnt;
}

int minMoves_2(vector<int> &nums) {
    int m = INT_MAX;
    long sum = 0;
    for (int i: nums) {
        m = min(m, i);
        sum += i;
    }

    return sum - m * nums.size();
}

int main() {

}