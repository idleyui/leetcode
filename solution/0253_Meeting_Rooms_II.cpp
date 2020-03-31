#include "alg.h"
//https://www.lintcode.com/problem/meeting-rooms-ii/description

static bool cmp(const Interval &i1, const Interval &i2) {
    return i1.start < i2.start;
}

int minMeetingRooms(vector<Interval> &intervals) {
    sort(intervals.begin(), intervals.end(), cmp);
    priority_queue<int, vector<int>, greater<int>> q;
    for (auto interval : intervals) {
        if (!q.empty() && q.top() <= interval.start) {
            q.pop();
        }
        q.push(interval.end);
    }
    return q.size();
}

int main() {

}