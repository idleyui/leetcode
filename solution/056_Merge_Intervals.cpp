#include "alg.h"

// Solution 1: sort and use stack
vector<vector<int>> merge(vector<vector<int>> &intervals) {
    // v1[1] <= v2[1] is wrong, equal item should return false in cmp function
    sort(intervals.begin(), intervals.end(), [](const vector<int> &v1, const vector<int> &v2) {
        return v1[0] < v2[0] || (v1[0] == v2[0] && v1[1] < v2[1]);
    });
    vector<vector<int>> merged = {};
    for (auto item: intervals) {
        if (merged.empty() || item[0] > merged.back()[1]) { merged.push_back(item); }
        else { merged.back()[1] = max(merged.back()[1], item[1]); }
    }
    return merged;
}

int main() {
    vector<vector<int>> intervals1 = {{1,  3},
                                      {2,  6},
                                      {8,  10},
                                      {15, 18}};
    for (const auto &item: merge(intervals1)) {
        print_container(item);
    }
}