#include "alg.h"

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