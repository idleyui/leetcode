#include "alg.h"

string decodeString(string s) {
    stack<int> nums;
    stack<string> strs;
    strs.push("");
    string str;
    int num = 0;
    for (char c: s) {
        if (isdigit(c)) {
            num = num * 10 + (c - '0');
        } else if (c == '[') {
            nums.push(num);
            num = 0;
            strs.push("");
        } else if (c == ']') {
            string tmp = strs.top();
            strs.pop();
            for (int i = 0; i < nums.top(); ++i) {
                strs.top() = strs.top() + tmp;
            }
            nums.pop();
        } else {
            strs.top() = strs.top() + c;
        }
    }
    return strs.top();
}

int main() {
    vector<string> v = {
            "3[a]2[bc]",
            "3[a2[c]]",
            "2[abc]3[cd]ef"
            "2[abc]3[cd3[]]ef"
            "3[]",
            "",
    };
    for (auto s: v) {
        cout << decodeString(s) << endl;
    }

}