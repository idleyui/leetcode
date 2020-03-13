#include "alg.h"

int longestPalindrome(string s) {
    vector<int> cnt('z' - 'A' + 1, 0);
    int len = 0;
    for (char c: s) {
        if (cnt[c - 'A'] == 0) cnt[c - 'A']++;
        else if (cnt[c - 'A'] == 1) {
            len += 2;
            cnt[c - 'A'] = 0;
        }
    }
    if (len < s.size()) return len + 1;
    return len;
}

int main() {

}