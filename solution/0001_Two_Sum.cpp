#include "alg.h"

vector<int> twoSum(vector<int> &nums, int target) {
    map<int, int> v2p;
    for (int i = 0; i < nums.size(); i++) {
        int to_target = target - nums[i];
        if (v2p.count(to_target)) {
            return {v2p[to_target], i};
        }
        v2p[nums[i]] = i;
    }
    return {};
}

int main() {
    vector<int> test{2, 7, 11, 13};
    print_container(twoSum(test, 9));
}