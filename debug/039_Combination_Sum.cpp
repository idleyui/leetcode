#include "alg.h"

set<unordered_multiset<int>> uniqSum(vector<int> &candidates, int target) {
    set<unordered_multiset<int>> results{};
    for (int num: candidates) {
//        if (target == num) {
            unordered_multiset<int> sets({num});
            results.insert(sets);
//        } else if (target > num) {
//            set<unordered_multiset<int>> recur_v = uniqSum(candidates, target - num);
//            for (auto item = recur_v.begin(); item != recur_v.end(); item++) {
//                auto um = *item;
//                um.insert(num);
//            }
//            if (!recur_v.empty()) results.insert(recur_v.begin(), recur_v.end());
//        }
    }
    return results;
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    set<unordered_multiset<int>> re = uniqSum(candidates, target);
    vector<vector<int>> vr;
    for (auto item = re.begin(); item != re.end(); item++){
        auto un = *item;
        vr.push_back(vector<int>(un.begin(), un.end()));
    }
    return vr;
}

int main() {
    vector<int> v1 = {2, 3, 6, 7};
    auto v = combinationSum(v1, 7);
    for (auto &v2: v) {
        print_container(v2);
    }
    cout << v.size();
}