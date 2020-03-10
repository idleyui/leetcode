#include "alg.h"

void update_dict(unordered_map<char, int> &d, char key, int plus) {
    if (d.count(key)) {
        d[key] += plus;
        if (d[key] == 0) {
            d.erase(key);
        }
    } else {
        d[key] = plus;
    }
}

vector<int> findAnagrams(string s, string p) {
    if (p.size() > s.size()) return {};
    unordered_map<char, int> need;
    unordered_set<char> char_set(p.begin(), p.end());
    unordered_map<char, int> overflow;
    for (char c: p) {
        update_dict(need, c, 1);
    }
    int i = 0;
    for (; i < p.size(); i++) {
        if (char_set.count(s[i])) {
            update_dict(need, s[i], -1);
        } else {
            update_dict(overflow, s[i], 1);
        }
    }

    vector<int> rt;
    for (; i < s.size(); i++) {
        if (need.size() == 0 && overflow.size() == 0) {
            rt.push_back(i - p.size());
        }
        if (char_set.count(s[i])) { update_dict(need, s[i], -1); }
        else { update_dict(overflow, s[i], 1); }
        char left = s[i - p.size()];
        if (char_set.count(left)) { update_dict(need, left, 1); }
        else { update_dict(overflow, left, -1); }
    }

    if (need.size() == 0 && overflow.size() == 0) {
        rt.push_back(i - p.size());
    }
    return rt;
}

int main() {
}