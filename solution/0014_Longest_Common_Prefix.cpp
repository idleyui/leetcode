#include "alg.h"

string longestCommonPrefix(vector<string> &strs) {
    if (strs.empty()) return "";
    int i = 0;
    while (strs[0].size() > i) {
        char c = strs[0][i];
        for (string s: strs) {
            if (s.size() <= i || s[i] != c)
                return strs[0].substr(0, i);
        }
        i++;
    }
    cout << i;
    return strs[0].substr(0, i);
}

int main() {

}