#include "alg.h"

int lengthOfLongestSubstring(string s) {
    map<int, int> s2p{};
    int max = 0;
    for (int begin = 0, i = 0; i < s.size(); i++) {
        if (s2p.find(s[i]) != s2p.end())
            begin = std::max(begin, s2p[s[i]] + 1);
        s2p[s[i]] = i;
        max = std::max(i - begin + 1, max);
    }
    return max;
}

int main() {
    cout << lengthOfLongestSubstring("abc");
}