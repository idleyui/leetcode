#include "alg.h"

vector<vector<int>> subsets(vector<int> &nums) {
    vector<vector<int>> result = {{}};
    for (auto n: nums) {
        vector<vector<int>> tmp = {};
        for (auto item: result) {
            item.push_back(n);
            tmp.push_back(item);
        }
        result.insert(result.end(), tmp.begin(), tmp.end());
    }
    return result;
}

int main() {
//    vector<int> nums = {1, 2, 3};
    vector<int> nums = {1};
    for (const auto &subset: subsets(nums)) {
        print_container(subset);
    }
}