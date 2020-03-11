#include "alg.h"


bool wordPattern(string pattern, string str) {
    vector<string> strs = split(str, " ");
    unordered_map<char, int> char2pos;
    unordered_map<string, int> string2pos;
    if (strs.size() != pattern.size()) return false;
    for (int i = 0; i < pattern.size(); i++) {
        if (char2pos.count(pattern[i]) && string2pos.count(strs[i])) {
            if (char2pos[pattern[i]] != string2pos[strs[i]]) return false;
        } else if (!char2pos.count(pattern[i]) && !string2pos.count(strs[i])) {
            char2pos[pattern[i]] = i;
            string2pos[strs[i]] = i;
        } else {
            return false;
        }
    }
    return true;
}

int main() {

}