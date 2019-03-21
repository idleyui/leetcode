#include "alg.h"

bool isValid(string s) {
    vector<char> stack;
    for (char c: s) {
        if (c == '(' || c == '[' || c == '{') {
            stack.push_back(c);
        } else {
            if (stack.empty()) return false;
            char top = *(stack.end() - 1);
            if (top == '(' && c == ')' ||
                top == '[' && c == ']' ||
                top == '{' && c == '}' ) {
                stack.pop_back();
            } else {
                return false;
            }
        }
    }
    return stack.empty();
}

int main() {
    cout << isValid("") << isValid("()[]{}") << isValid("(]") << isValid("([)]") << isValid("{[]}");
}