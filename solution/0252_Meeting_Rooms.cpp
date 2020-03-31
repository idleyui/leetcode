#include "alg.h"
//https://www.lintcode.com/problem/meeting-rooms/description

static bool cmp(const Interval &i1, const Interval &i2) {
    return i1.start < i2.start;
}

bool canAttendMeetings(vector<Interval> &intervals) {
    sort(intervals.begin(), intervals.end(), cmp);
    int rightmost = 0;
    for (const Interval &i: intervals) {
        if (i.start < rightmost) return false;
        rightmost = max(rightmost, i.end);
    }
    return true;
}

int main() {

}