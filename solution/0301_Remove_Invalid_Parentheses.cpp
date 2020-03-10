#include "alg.h"

vector<string> removeInvalidParentheses(string s) {
    stack<char> stk;
    for (char c: s) {
        if (c == '(') {
            stk.push(c);
        } else if (c == ')') {

        } else {
            stk.push(c);
        }
    }
}

int main() {

}