#include "alg.h"


//https://leetcode.com/problems/generate-parentheses/discuss/10100/Easy-to-understand-Java-backtracking-solution
//https://leetcode.com/problems/generate-parentheses/discuss/10105/Concise-recursive-C%2B%2B-solution
// count (-open, )-close char amount and append
void backtrack(vector<string> &result, string local, int max_open, int open, int close) {
    if (local.size() == max_open * 2) result.push_back(local);
    if (open < max_open) backtrack(result, local + '(', max_open, open + 1, close);
    if (close < open) backtrack(result, local + ')', max_open, open, close + 1);
}

vector<string> generateParenthesisOpenClose(int n) {
    vector<string> result;
    backtrack(result, "", 0, 0, 0);
    return result;
}

void generateParenthesisRec(int n, int leftflow, string basic, set<string> &sset) {
    if (leftflow < 0)return;
    if (n == 0) {
        if (leftflow == 0) sset.insert(basic);
        return;
    }
    generateParenthesisRec(n - 1, leftflow + 1, basic + '(', sset);
    generateParenthesisRec(n - 1, leftflow - 1, basic + ')', sset);
}

vector<string> generateParenthesisRec(int n) {
    set<string> sset;
    generateParenthesisRec(n * 2, 0, "", sset);
    return vector<string>(sset.begin(), sset.end());
}

vector<string> generateParenthesis(int n) {
    set<string> sset;
    sset.insert("");
    for (int i = 0; i < n; ++i) {
        set<string> newset;
        for (string s:sset) {
            newset.insert("()" + s);
            for (int j = 0; j < s.size(); ++j) {
                if (s[j] == '(') {
                    string s1 = s;
                    s1.insert(j + 1, "()");
                    newset.insert(s1);
                }
            }
        }
        sset = newset;
    }
    return vector<string>(sset.begin(), sset.end());
}

int main() {
//    for (int i = 0; i < 5; ++i) {
//        print_container(generateParenthesis(i), "\n");
//    }
    for (int i = 0; i < 5; ++i) {
        print_container(generateParenthesisRec(i), "\n");
    }
}