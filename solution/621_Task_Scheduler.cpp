#include "alg.h"

// https://leetcode.com/problems/task-scheduler/discuss/104504/C%2B%2B-8lines-O(n)
int leastInterval(vector<char> tasks, int n) {
    unordered_map<char, int> mp;
    int cnt = 0;
    for (auto c: tasks) {
        mp[c]++;
        cnt = max(cnt, mp[c]);
    }
    int ans = (cnt - 1) * (n + 1);
    for (auto e: mp)if (e.second == cnt)ans++;
    return max((int) tasks.size(), ans);
}

int main() {
    cout << leastInterval({'A', 'A', 'A', 'B', 'B', 'B'}, 2);
    cout << leastInterval({'A', 'A', 'A', 'B', 'B', 'B'}, 100);
    cout << leastInterval({'A', 'A', 'A', 'B', 'B', 'B'}, 1);
}