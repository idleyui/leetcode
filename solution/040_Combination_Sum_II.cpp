#include "alg.h"

// Solution 1: backtrack
void backtrack(vector<vector<int>> &result, vector<int> &candidates, vector<int> tmp, int target, int start) {
    if (target == 0) {
        result.push_back(tmp);
        return;
    }
    for (int i = start; i < candidates.size() && candidates[i] <= target; i++) {
        if (i != start && candidates[i] == candidates[i - 1]) continue;
        tmp.push_back(candidates[i]);
        backtrack(result, candidates, tmp, target - candidates[i], i + 1);
        tmp.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> result;
    backtrack(result, candidates, {}, target, 0);
    return result;
}

// Solution 2: set
set<vector<int>> uniqSum(vector<int> &candidates, int target, int start) {
    set<vector<int>> rt;
    for (int j = start; j < candidates.size(); j++) {
        int i = candidates[j];
        if (target == i)rt.insert({i});
        else if (target > i) {
            set<vector<int>> append = uniqSum(candidates, target - i, j + 1);
            for (vector<int> s: append) {
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
    auto sets = uniqSum(candidates, target, 0);
    vector<vector<int>> rt(sets.begin(), sets.end());
    return rt;
}

int main() {
    vector<int> v1 = {2, 3, 5};
    auto v = combinationSum1(v1, 8);
    for (auto &v2: v) {
        print_container(v2);
    }
}