#include "alg.h"

bool canConstruct(string ransomNote, string magazine) {
    vector<int> cnt(26, 0);
    for (char c: ransomNote) cnt[c - 'a']++;

    int use = 0;
    for (char c: magazine) {
        if (cnt[c - 'a'] > 0) {
            cnt[c - 'a']--;
            use++;
        }
    }

    return use == ransomNote.size();
}

int main() {

}