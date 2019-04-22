#include "alg.h"

int minAddToMakeValid(string S) {
    stack<char> stk;
    int add = 0;
    for (char c: S) {
        if (c == '(') {
            stk.push(c);
        } else {
            if (!stk.empty()) {
                stk.pop();
            } else {
                add += 1;
            }
        }
    }
    return add + stk.size();
}

int main() {
    cout << minAddToMakeValid("())") << endl;
    cout << minAddToMakeValid("(((") << endl;
    cout << minAddToMakeValid(")))") << endl;
    cout << minAddToMakeValid("()(()()())))") << endl;
    cout << minAddToMakeValid("()") << endl;
}