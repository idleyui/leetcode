#include "alg.h"

// Solution 1: char map
char findTheDifference(string s, string t) {
    vector<int> cnt(26, 0);
    for (int i = 0; i < s.size(); i++) {
        cnt[s[i] - 'a']--;
        cnt[t[i] - 'a']++;
    }
    cnt[t[t.size() - 1] - 'a']++;
    for (int i = 0; i < 26; i++) {
        if (cnt[i] > 0) return 'a' + i;
    }
    return 'a';
}

// Solution 2: xor
char findTheDifference_2(string s, string t) {
    char result = 0;
    for (int i = 0; i < s.size(); i++) {
        result ^= s[i];
        result ^= t[i];
    }
    result ^= t[t.size() - 1];
    return result;
}

int main() {
    cout << findTheDifference("abcd", "abcde");
}