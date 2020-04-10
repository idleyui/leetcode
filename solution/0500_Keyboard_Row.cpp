#include "alg.h"


vector<string> findWords(vector<string> &words) {
    vector<string> keyboard = {
            "qwertyuiop", "asdfghjkl", "zxcvbnm"
    };
    vector<int> cnt(26, 0);
    for (int i = 0; i < 3; i++) {
        for (char c: keyboard[i]) {
            cnt[c - 'a'] = i;
        }
    }

    vector<string> ans;
    for (string &word: words) {
        bool in = true;
        for (int i = 1; i < word.size(); i++) {
            if (cnt[tolower(word[i]) - 'a'] != cnt[tolower(word[i - 1]) - 'a']) {
                in = false;
                break;
            }
        }
        if (in) ans.push_back(word);
    }
    return ans;
}

int main() {

}