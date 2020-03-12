#include "alg.h"

int firstUniqChar(string s) {
    vector<int> cnt(26, -1);
    int idx = 1;
    for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        if (cnt[c - 'a'] == -1) cnt[c - 'a'] = i;
        else if (cnt[c - 'a'] > -1) cnt[c - 'a'] = -2;
    }
    int min_v = s.size();
    for (int i = 0; i < 26; i++) {
        if (cnt[i] >= 0 && cnt[i] < min_v) {
            min_v = cnt[i];
        }
    }
    return min_v == s.size() ? -1 : min_v;
}

int main() {

}