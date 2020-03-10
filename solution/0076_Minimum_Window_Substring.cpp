#include "alg.h"

//https://leetcode.com/problems/minimum-window-substring/discuss/26808/Here-is-a-10-line-template-that-can-solve-most-'substring'-problems
string minWindow(string s, string t) {
    unordered_map<char, int> charcnt;
    for (char c: t) {
        if (charcnt.count(c)) charcnt[c]++;
        else charcnt[c] = 1;
    }
    int slow = 0, fast = 0, cnt = t.size(), w = INT_MAX, w_begin = 0;

    while (fast < s.size()) {
        if (charcnt.count(s[fast]) && charcnt[s[fast]]-- > 0) cnt--;
        fast++;
        while (cnt == 0) {
            if (fast - slow < w) w = fast - (w_begin = slow);
            if (charcnt.count(s[slow]) && charcnt[s[slow]]++ == 0) cnt++;
            slow++;
        }
        // cout << fast << slow << ',';
    }
    // cout << w_begin;
    return w == INT_MAX ? "" : s.substr(w_begin, w);
}

int main() {

}