#include "alg.h"

int longestValidParentheses_n2(string s) {
    vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
    int max = 0;
    for (int i = 0; i < s.size(); i++) {
        dp[i][i] = s[i] == '(' ? 1 : -1;
    }

    for (int len = 2; len <= s.size(); len++) {
        for (int i = 0; i < s.size() - len + 1; i++) {
            if (dp[i][i + len - 2] < 0) dp[i][i + len - 1] = dp[i][i + len - 2];
            else dp[i][i + len - 1] = dp[i][i + len - 2] + (s[i + len - 1] == '(' ? 1 : -1);
            if (dp[i][i + len - 1] == 0) max = len;
        }
    }
    return max;
}

int longestValidParentheses_dp(string s) {
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

int longestValidParentheses_stack(string s) {
    if (s.size() < 2) return 0;
    stack<int> stk({-1});
    int max = 0;

    for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        if (c == '(') stk.push(i);
        else {
            stk.pop();
            if (stk.empty()) stk.push(i);
            else max = max > i - stk.top() ? max : i - stk.top();
        }
    }

    return max;
}

int longestValidParentheses_left_right(string s) {
    if (s.size() < 2) return 0;
    int left = 0, right = 0, val = 0;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') left++;
        else right++;
        if (right > left) {
            left = right = 0;
        }
        if (left == right) val = max(val, left + right);
    }

    left = 0;
    right = 0;
    for (int i = s.size() - 1; i >= 0; i--) {
        if (s[i] == '(') left++;
        else right++;
        if (left > right) left = right = 0;
        if (left == right) {
            val = max(val, left + right);
        }

    }
    return val;
}

int main() {
    auto arr = {"()()()", "", ")()((()())"};
    for (auto s: arr)
//        cout << longestValidParentheses_stack(s);
        cout << longestValidParentheses_left_right(s);
}