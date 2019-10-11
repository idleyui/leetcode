#include "alg.h"

vector<vector<int>> merge(vector<vector<int>> &intervals) {
    sort(intervals.begin(), intervals.end(), [](const vector<int> &v1, const vector<int> &v2) {
        return v1[0] < v2[0] || (v1[0] == v2[0] && v1[1] < v2[1]);
    });

    intervals.push_back({INT_MAX, INT_MAX});
    vector<vector<int>> result = {};
    auto buf = intervals[0];
    for (auto item: intervals) {
        if (item[0] <= buf[1]) {
            buf[1] = max(buf[1], item[1]);
        } else {
            result.push_back(buf);
            buf = item;
        }
    }

    return result;
}

int main() {
    vector<vector<int>> intervals1 = {{1,  3},
                                     {2,  6},
                                     {8,  10},
                                     {15, 18}};
    for (const auto &item: merge(intervals)) {
        print_container(item);
    }
}