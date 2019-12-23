#include "alg.h"

//     begin, max, v2p
int lengthOfLongestSubstring(string s) {
    map<char, int> v2p;
    int begin = 0, max_len = 0;
    for (int i = 0; i < s.size(); i++) {
        char item = s[i];
        if (v2p.count(item)) {
            begin = max(begin, v2p[item] + 1);
        }
        v2p[item] = i;
        max_len = max(max_len, i - begin + 1);
    }
    return max_len;
}


int main() {
    cout << lengthOfLongestSubstring("abc");
}