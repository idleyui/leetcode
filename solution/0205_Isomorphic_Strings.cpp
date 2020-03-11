#include "alg.h"

// todo discuss
bool isIsomorphic(string s, string t) {
    unordered_map<char, int> s_map;
    unordered_map<char, int> t_map;
    if (s.size() != t.size()) return false;
    for (int i = 0; i < s.size(); i++) {
        if (s_map.count(s[i]) && t_map.count(t[i])) {
            if (s_map[s[i]] != t_map[t[i]]) return false;
        } else if (!s_map.count(s[i]) && !t_map.count(t[i])) {
            s_map[s[i]] = i;
            t_map[t[i]] = i;
        } else {
            return false;
        }
    }
    return true;
}

int main() {

}