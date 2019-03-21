#include "alg.h"


void combinationSum(vector<int> &candidates, int target, vector<vector<int>> &res, vector<int> combination, int begin) {
    if (!target) {
        res.push_back(combination);
        return;
    }
    for (int i = begin; i != candidates.size() && target >= candidates[i]; ++i) {
        combination.push_back(candidates[i]);
        combinationSum(candidates, target - candidates[i], res, combination, i);
        combination.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> res;
    vector<int> combination;
    combinationSum(candidates, target, res, combination, 0);
    return res;
}

int main() {
    vector<int> v1 = {2, 3, 6, 7};
    auto v = combinationSum(v1, 7);
    for (auto &v2: v) {
        print_container(v2);
    }
}