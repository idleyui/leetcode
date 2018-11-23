#include "alg.h"

map<char, int> create_map(string s, int len) {
    map<char, int> cntp;
    for (int i = 0; i < len; i++) {
        char c = s[i];
        if (cntp.count(c)) {
            cntp[c] = cntp[c] + 1;
        } else {
            cntp[c] = 1;
        }
    }
    return cntp;
}

bool equl(map<char, int> m1, map<char, int> m2) {
    if (m1.size() != m2.size())return false;
    for (auto item = m1.begin(); item != m1.end(); item++) {
        if (item->second != m2[item->first])return false;
    }
    return true;
}

vector<int> findAnagrams(string s, string p) {
    vector<int> r;
    if (p.size() > s.size()) return {};
    map<char, int> cntp = create_map(p, p.size());
    map<char, int> window = create_map(s, p.size());
    for (int i = p.size(); i < s.size(); i++) {
        int begin = i - p.size();
        if (equl(cntp, window)) r.push_back(begin);

        for (auto item: window) {
            cout << item.first;
        }
        cout << endl;
        s[begin]--;
//        window.erase(s[begin]);
        // window.erase()
        window[s[i]]++;

    }
    return r;
}

int main() {
//    string s = "c";
//    map<char, int> window;
//    window['a'] = 2;
//    window['b'] = 1;
//    window['c'] = 0;
//    for (auto item = window.begin(); item != window.end(); item++) {
//        cout << item->first;
//    }
//    cout << endl;
//    window.erase(s[0]);
//    for (auto item = window.begin(); item != window.end(); item++) {
//        cout << item->first;
//    }

    print_container(findAnagrams("cbaebabacd", "abc"));
}