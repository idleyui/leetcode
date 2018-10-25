#include "alg.h"

string longestCommonPrefix(vector<string> &strs) {
    if (strs.size() == 0)return "";
    int i = 0;
    bool match = true;
    while (match && i < strs[0].size()) {
        char c = strs[0][i];
        for (string &s: strs) {
            if (i >= s.size() || s[i] != c) {
                match = false;
                break;
            }
        }
        if (!match)break;
        else i++;
    }
    return strs[0].substr(0, i);
}

int main() {

}