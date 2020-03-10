#include "alg.h"

//https://leetcode.com/problems/longest-consecutive-sequence/discuss/41088/Possibly-shortest-cpp-solution-only-6-lines.
int longestConsecutive(vector<int> &nums) {
    unordered_map<int, int> val2len;
    int max_len = 0;
    for (int i: nums) {
        if (val2len.count(i)) continue;
        int left = val2len.count(i - 1) ? val2len[i - 1] : 0;
        int right = val2len.count(i + 1) ? val2len[i + 1] : 0;
        int new_len = left + right + 1;
        for (int num = i - 1; num > i - 1 - left; num--) {
            val2len[num] = new_len;
        }
        for (int num = i + 1; num < i + 1 + right; num++) {
            val2len[num] = new_len;
        }
        val2len[i] = new_len;
        max_len = max(max_len, new_len);
    }
    return max_len;
}

int main() {

}