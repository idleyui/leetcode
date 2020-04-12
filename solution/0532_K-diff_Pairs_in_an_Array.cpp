#include "alg.h"

int findPairs(vector<int> &nums, int k) {
    if (k < 0) return 0;
    unordered_map<int, int> num_cnt;
    for (int i: nums) num_cnt[i]++;
    int cnt = 0;
    if (k == 0) {
        for (auto p: num_cnt) {
            if (p.second > 1) cnt++;
        }
        return cnt;
    }
    for (auto p: num_cnt) {
        if (num_cnt.count(p.first - k)) cnt++;
        if (num_cnt.count(p.first + k)) cnt++;
    }
    return cnt / 2;
}

int main() {

}