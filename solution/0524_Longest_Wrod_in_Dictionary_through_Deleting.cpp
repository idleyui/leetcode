#include "alg.h"

string findLongestWord(string s, vector<string> &d) {
    string ans = "";
    for (string &word: d) {
        int p1 = 0, p2 = 0;
        while (p1 < s.size() && p2 < word.size()) {
            if (s[p1] == word[p2]) {
                p2++;
            }
            p1++;
        }
        if (p2 == word.size()) {
            if (word.size() > ans.size() || (word.size() == ans.size() && word < ans))
                ans = word;
        }
    }
    return ans;
}

int main() {
    cout << ("ab" < "ba");
}