#include "alg.h"

string sortString(string s) {
    vector<int> cnt(26, 0);
    for (char c: s) cnt[c - 'a']++;
    string result;
    while (result.size() < s.size()) {
        for (int i = 0; i < 26; i++) {
            if (cnt[i] > 0) {
                result += (char) ('a' + i);
                cnt[i]--;
            }
        }
        for (int i = 25; i >= 0; i--) {
            if (cnt[i] > 0) {
                result += (char) ('a' + i);
                cnt[i]--;
            }
        }
    }
    return result;
}

int main() {

}