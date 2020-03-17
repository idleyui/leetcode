#include "alg.h"

int findMaxConsecutiveOnes(vector<int> &nums) {
    int max_cnt = 0, cur_cnt = 0;
    for (int i: nums) {
        if (i == 0) {
            cur_cnt = 0;
            continue;
        }
        cur_cnt++;
        max_cnt = max(max_cnt, cur_cnt);
    }
    return max_cnt;
}

int main() {

}