#include "alg.h"


bool eq(string &s, char c) {
    if (s.size() > 1) return false;
    return s[0] == c;
}

vector<vector<string>> partition(string s) {
    vector<vector<string>> rt = {{}};
    for (char c: s) {
        vector<vector<string>> append;
        for (vector<string> &v: rt) {
            if (v.size() > 0 && eq(v.back(), c)) {
                vector<string> v_copy(v.begin(), v.end());
                v_copy.back() = v_copy.back() + c;
                append.push_back(v_copy);
            }
            if (v.size() > 1 && eq(v[v.size() - 2], c)) {
                vector<string> v_copy(v.begin(), v.end());
                v_copy.pop_back();
                v_copy.back() = v[v.size() - 2] + v.back() + c;
                append.push_back(v_copy);
            }
            vector<string> v_copy(v.begin(), v.end());
            v_copy.push_back(string(1, c));
            append.push_back(v_copy);
        }
        rt = append;
    }
    return rt;
}

int main() {
    vector<int> v1 = {1, 2, 3};
    vector<int> v2 = {1, 2, 3};
}