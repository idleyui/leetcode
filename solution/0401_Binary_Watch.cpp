#include "alg.h"

// Solution 1: backtrack + bit
void combine(vector<int> &result, int tmp, int cur, int num) {
    if (num == 0) {
        result.push_back(tmp);
        return;
    }
    if (cur == 0) return;
    combine(result, tmp, cur >> 1, num);
    combine(result, tmp | cur, cur >> 1, num - 1);
}

vector<string> readBinaryWatch_1(int num) {
    vector<int> v;
    combine(v, 0, 1 << 9, num);

    vector<string> time;
    for (int i: v) {
        int hour = i >> 6;
        int min = i & 0x3f;
        if (hour > 11 || min > 59) continue;
        string min_str = to_string(min);
        if (min_str.size() == 0) min_str = "00";
        if (min_str.size() == 1) min_str = "0" + min_str;
        time.push_back(to_string(hour) + ":" + min_str);
    }
    return time;
}

// bottom up combination and filter by condition
// https://leetcode.com/problems/binary-watch/discuss/88465/Straight-forward-6-line-c%2B%2B-solution-no-need-to-explain
vector<string> readBinaryWatch_2(int num) {
    vector<string> result;
    for (int hour = 0; hour < 12; hour++) {
        for (int min = 0; min < 60; min++) {
            if (bitset<10>(hour << 6 | min).count() == num) {
                result.push_back(to_string(hour) + ":" + (min < 10 ? "0" : "") + to_string(min));
            }
        }
    }
    return result;
}

int main() {

}