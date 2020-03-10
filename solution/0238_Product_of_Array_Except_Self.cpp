#include "alg.h"

vector<int> productExceptSelf(vector<int> &nums) {
    int output = 1;
    int zero_cnt = 0;
    int zero_pos = -1;
    for (int i = 0; i < nums.size() && zero_cnt <= 1; i++) {
        int num = nums[i];
        if (num == 0) {
            zero_cnt++;
            zero_pos = i;
            continue;
        }
        output = output * num;
    }
    if (zero_cnt > 1) {
        return vector<int>(nums.size(), 0);
    } else if (zero_cnt == 1) {
        vector<int> rt(nums.size(), 0);
        rt[zero_pos] = output;
        return rt;
    } else {
        vector<int> result = {};
        result.reserve(nums.size());
        for (int i: nums) {
            result.push_back((output / i));
        }
        return result;
    }
}

int main() {
}