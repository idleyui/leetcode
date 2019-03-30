#include "alg.h"

NestedInteger deserialize(string s) {
    stack<NestedInteger> stk;
    stk.push(NestedInteger());
    int num = 0;
    bool plus = true;
    for (int i = 0; i < s.size(); i++) {
        char c = s[i];

        if (c == '[') {
            stk.push(NestedInteger());
        } else if (c == ']' || c == ',') {
            if (isdigit(s[i - 1])) {
                stk.top().add(NestedInteger(plus ? num : -num));
                num = 0;
                plus = true;
            }
            if (c == ']') {
                auto ni = stk.top();
                stk.pop();
                stk.top().add(ni);
            }
        } else if (c == '-') {
            plus = false;
        } else {
            num = num * 10 + (c - '0');
        }
    }
    return s[0] == '[' ? stk.top() : NestedInteger(num);
}

int main() {

}