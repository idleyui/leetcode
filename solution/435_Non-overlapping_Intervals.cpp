#include "alg.h"

bool comp(const vector<int> &a, const vector<int> &b) {
    return a[0] < b[0] || (a[0] == b[0] && a[1] < b[1]);
}

int eraseOverlapIntervals(vector<vector<int>> intervals) {
    if (intervals.empty())return 0;
    int cnt = 0;
    sort(intervals.begin(), intervals.end(), comp);
    auto cur = intervals[0];
    for (int i = 1; i < intervals.size(); ++i) {
        if (intervals[i][1] <= cur[1]){
            cnt++;
            cur = intervals[i];
        }else if(intervals[i][0] >= cur[1]){
            cur = intervals[i];
        }else{
            cnt++;
        }
    }
    return cnt;
}

int main() {
    cout << eraseOverlapIntervals({{1, 2},
                                   {2, 3},
                                   {3, 4},
                                   {1, 3}});
    cout << eraseOverlapIntervals({{1, 2},
                                   {1, 2},
                                   {1, 2}});
    cout << eraseOverlapIntervals({{1, 2},
                                   {2, 3}});
    cout << eraseOverlapIntervals({{1, 2}});
    cout << eraseOverlapIntervals({});
    cout << eraseOverlapIntervals({{1,  100},
                                   {11, 22},
                                   {1,  11},
                                   {2,  12}});


}