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

set<vector<int>> uniqSum(vector<int> &candidates, int target) {
    set<vector<int>> rt;
    for (int i: candidates) {
        if (target == i)rt.insert({i});
        else if (target > i) {
            set<vector<int>> append = uniqSum(candidates, target - i);
            for(vector<int> s: append){
                if (i > s.back()) continue;
                s.push_back(i);
                rt.insert(s);
            }
        }
    }
    return rt;
}

vector<vector<int>> combinationSum1(vector<int> &candidates, int target) {
    sort(candidates.begin(), candidates.end());
    auto sets = uniqSum(candidates, target);
    vector<vector<int>> rt(sets.begin(), sets.end());
    return rt;
}

int main() {
//    vector<int> v1 = {2, 3, 6, 7};
//    auto v = combinationSum(v1, 7);
//    for (auto &v2: v) {
//        print_container(v2);
//    }
//    vector<int> v1 = {2, 3, 6, 7};
    vector<int> v1 = {2, 3, 5};
//    auto v = combinationSum1(v1, 7);
    auto v = combinationSum1(v1, 8);
    for (auto &v2: v) {
        print_container(v2);
    }
}