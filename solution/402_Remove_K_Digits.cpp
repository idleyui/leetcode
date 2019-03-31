#include "alg.h"

string removeKdigits(string num, int k) {
    string s;
    int i = 0;
    for (; i < num.size(); i++) {
        char c = num[i];
        if (k == 0) {
            break;
        }
        if (c == '0' && s.empty()) { if (s.empty())continue; }
        else if (c == '0' && s.size() == 1) {
            s.pop_back();
            k--;
        } else if (s.empty()) {
            s.push_back(c);
        } else {
            char top = s.back();
            while (!s.empty() && c <= top) {
                k--;
                s.pop_back();
            }
            s.push_back(c);
        }
    }
    string rt = (k < s.size() ? s.substr(k) : "") + num.substr(i);
    return rt.size() > 0 ? rt : "0";
}

int main() {
    cout << removeKdigits("1432219", 3) << endl;
    cout << removeKdigits("10200", 1) << endl;
    cout << removeKdigits("10", 2) << endl;
    cout << removeKdigits("10201", 2) << endl;
    cout << removeKdigits("212", 2) << endl;
}