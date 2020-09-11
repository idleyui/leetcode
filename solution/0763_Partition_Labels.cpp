#include "alg.h"

bool cmp(const pair<char, pair<int, int>> &p1, const pair<char, pair<int, int>> &p2) {
    if (p1.second.first == -1 && p1.second.second == -1)return false;
    if (p2.second.first == -1 && p2.second.second == -1)return true;
    return p1.second.first < p2.second.first ||
           (p1.second.first == p2.second.first && p1.second.second < p2.second.second);
}

vector<int> partitionLabels_naive(string S) {
    if (S.empty())return {};
    vector<pair<char, pair<int, int>>> cnt(26, {'a', {-1, -1}});
    for (int i = 0; i < 26; ++i) { cnt[i] = {'a' + i, {-1, -1}}; }
    for (int j = 0; j < S.size(); ++j) {
        char c = S[j];
        if (cnt[c - 'a'].second.first == -1) { cnt[c - 'a'].second.first = j; }
        cnt[c - 'a'].second.second = j;
    }
    sort(cnt.begin(), cnt.end(), cmp);
    while (cnt.back().second.first == -1 && cnt.back().second.second == -1) { cnt.pop_back(); }

    auto base = cnt[0].second;
    vector<int> result = {};
    int last = 0;
    for (int i = 1; i < cnt.size(); ++i) {
        auto right = cnt[i].second;
        if (right.first > base.second) {
            result.push_back(right.first - last);
            last = right.first;
            base = cnt[i].second;
        } else if (right.first < base.second) {
            if (right.second > base.second) {
                base = cnt[i].second;
            }
        }
    }

    result.push_back(S.size() - last);
    return result;
}

// idea from 56. merge intervals
vector<int> partitionLabels(string S) {
    vector<vector<int>> interval(26, {(int) S.size(), 0});
    for (int i = 0; i < S.size(); i++) {
        int c = S[i] - 'a';
        interval[c][0] = min(interval[c][0], i);
        interval[c][1] = max(interval[c][1], i);
    }

    sort(interval.begin(), interval.end(), [](const vector<int> &v1, const vector<int> &v2) {
        return v1[0] < v2[0];
    });

    vector<vector<int>> stk;
    for (auto v: interval) {
        if (v[0] == S.size()) break;
        if (stk.empty()) stk.push_back(v);
        else if (v[0] < stk.back()[1]) stk.back()[1] = max(stk.back()[1], v[1]);
        else stk.push_back(v);
    }
    vector<int> ans;
    for (auto v: stk) {
        ans.push_back(v[1] - v[0] + 1);
    }
    return ans;
}

// https://leetcode.com/problems/partition-labels/discuss/113259/Java-2-pass-O(n)-time-O(1)-space-extending-end-pointer-solution
// two pointer solution
vector<int> partitionLabels_2(string S) {
    vector<int> last(26, 0);
    for (int i = 0; i < S.size(); i++) { last[S[i] - 'a'] = i; }

    vector<int> ans;
    int left = 0, right = 0;
    for (int i = 0; i < S.size(); i++) {
        int c = S[i] - 'a';
        right = max(last[c], right);
        if (right == i) {
            ans.push_back(right - left + 1);
            left = right + 1, right = left;
        }
    }
    return ans;
}

int main() {
    vector<string> v = {
            "ababcbacadefegdehijhklij",
            "abcdefja",
            "caedbdedda"
    };
    for (auto s: v) {
        print_container(partitionLabels_2(s));
    }
}