#include "alg.h"

bool comp(const pair<int, int> &a, const pair<int, int> &b) {
    return a.second < b.second || (a.second == b.second && a.first < b.first);
}

int findMinArrowShots(vector<pair<int, int>> points) {
    sort(points.begin(), points.end(), comp);
    int end = points[0].second;
    int cnt = 1;
    for (auto p: points) {
        if (p.first > end) {
            cnt++;
            end = p.second;
        }
    }

    return cnt;
}

int main() {
    cout << findMinArrowShots({{10, 16},
                               {2,  8},
                               {1,  6},
                               {7,  12}});
    cout << findMinArrowShots({{1, 16},
                               {1, 6},
                               {7, 12}});
    cout << findMinArrowShots({{1, 16},
                               {1, 7},
                               {7, 12}});
    cout << findMinArrowShots({{1, 7},
                               {7, 12}});
    cout << findMinArrowShots({{INT_MIN, INT_MAX}});
    cout << findMinArrowShots({{9, 12},
                               {1, 10},
                               {4, 11},
                               {8, 12},
                               {3, 9},
                               {6, 9},
                               {6, 7}});
}