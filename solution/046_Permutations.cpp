#include "alg.h"

void backtrack(vector<vector<int>> &result, vector<int> tmp, vector<int> &nums) {
    if (tmp.size() == nums.size()) result.push_back(tmp);
    else {
        for (int i = 0; i < nums.size(); i++) {
            if (find(tmp.begin(), tmp.end(), nums[i]) != tmp.end()) continue;
            tmp.push_back(nums[i]);
            backtrack(result, tmp, nums);
            tmp.pop_back();
        }
    }
}

vector<vector<int>> permute(vector<int> &nums) {
    vector<vector<int>> result = {};
    backtrack(result, {}, nums);
    return result;
}

int main() {
//    vector<int> vv = {1, 2, 3};
    vector<int> vv = {};
    for (auto v: permute(vv)) {
        print_container(v);
    }
}