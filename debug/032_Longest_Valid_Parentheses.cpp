#include "alg.h"

int longestValidParentheses(string s) {
    if (s.empty()) return 0;
    vector<int> status(s.size());
    int max = 0;
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == ')') {
            if (s[i - 1] == '(') {
                status[i] = 2;
                if (i - 2 > 0) status[i] = status[i] + status[i - 2];
            } else if (s[i - 1] == ')' && i - status[i - 1] - 1 >= 0 && s[i - status[i - 1] - 1] == '(') {
                status[i] = status[i - 1] + 2;
                if (i - status[i - 1] - 2 > 0) {
                    status[i] += status[i - status[i - 1] - 2];
                }
            } else {
                status[i] = 0;
            }
        } else {
            status[i] = 0;
        }
        if (status[i] > max) max = status[i];
    }
    return max;
}

int main() {
    cout << longestValidParentheses("))()()");
}