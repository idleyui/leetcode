#include "alg.h"

vector<int> twoSum(vector<int> &nums, int target) {
    map<int, int> comp_map = {};
    for (int i = 0; i < nums.size(); i++) {
        int comp = target - nums[i];
        if (comp_map.find(comp) != comp_map.end()) {
            return {comp_map[comp], i};
        }
        comp_map[nums[i]] = i;
    }
}

int main() {
    vector<int> test{2, 7, 11, 13};
    print_container(twoSum(test, 9));
}