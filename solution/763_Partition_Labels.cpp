#include "alg.h"

bool cmp(const pair<char, pair<int, int>> &p1, const pair<char, pair<int, int>> &p2) {
    if (p1.second.first == -1 && p1.second.second == -1)return false;
    if (p2.second.first == -1 && p2.second.second == -1)return true;
    return p1.second.first < p2.second.first ||
           (p1.second.first == p2.second.first && p1.second.second < p2.second.second);
}

vector<int> partitionLabels(string S) {
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

int main() {
    vector<string> v = {
            "ababcbacadefegdehijhklij",
            "abcdefja",
            "abcdefja"
    };
    for(auto s: v){
        print_container(partitionLabels(s));
    }
}