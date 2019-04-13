#include "alg.h"

bool isSubsequence2(string s, string t) {
    if (s.size() > t.size()) return false;
    while (!t.empty() && !s.empty()) {
        if (t.back() == s.back()) {
            s.pop_back();
            t.pop_back();
        } else {
            t.pop_back();
        }
    }
    return s.empty();
}

bool isSubsequence(string s, string t) {
    int pos = 0;
    for (char c: t) {
        if (pos == s.size()) break;
        if (c == s[pos]) {
            pos++;
        }
    }
    return pos == s.size();
}

int main() {
    cout << isSubsequence("abc", "ahbgdc") << endl;
    cout << isSubsequence("axc", "ahbgdc") << endl;
    cout << isSubsequence("", "abc") << endl;
    cout << isSubsequence("abc", "abc") << endl;
}