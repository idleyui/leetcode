#include "alg.h"

bool isValid(string s) {
    stack<char> par;
    for (char c: s) {
        if (c == '(' || c == '[' || c == '{') {
            par.push(c);
        } else {
            if (par.empty()) return false;
            if (par.top() == '(' && c == ')' ||
                par.top() == '[' && c == ']' ||
                par.top() == '{' && c == '}') {
                par.pop();
            } else {
                return false;
            }
        }
    }
    return par.empty();
}

int main() {
    cout << isValid("") << isValid("()[]{}") << isValid("(]") << isValid("([)]") << isValid("{[]}");
}