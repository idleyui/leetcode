#include "alg.h"

// Solution 1: backtrack
// https://leetcode.com/problems/permutations/discuss/18239/A-general-approach-to-backtracking-questions-in-Java-(Subsets-Permutations-Combination-Sum-Palindrome-Partioning)
bool isPalidrome(string &s, int i, int j) {
    for (; i < j; i++, j--) {
        if (s[i] != s[j]) return false;
    }
    return true;
}

void backtrack(vector<vector<string>> &result, string &s, vector<string> tmp, int start) {
    if (start >= s.size()) {
        result.push_back(tmp);
        return;
    }
    for (int i = start; i < s.size(); i++) {
        if (!isPalidrome(s, start, i)) continue;
        tmp.push_back(s.substr(start, i - start + 1));
        backtrack(result, s, tmp, i + 1);
        tmp.pop_back();
    }
}

vector<vector<string>> partition1(string s) {
    vector<vector<string>> result;
    backtrack(result, s, {}, 0);

    return result;
}


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