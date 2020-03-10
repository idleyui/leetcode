#include "alg.h"

//https://leetcode.com/problems/remove-k-digits/discuss/88743/C%2B%2B-6ms-10-lines-solution-with-comments
string removeKdigits(string num, int k) {
    string ans;

    for (char c: num) {
        while (ans.size() && ans.back() > c && k) {
            ans.pop_back();
            k--;
        }
        if (ans.size() || c != '0') { ans.push_back(c); }
    }
    while (ans.size() && k--) { ans.pop_back(); }
    return ans.empty() ? "0" : ans;
}

int main() {
//    cout << removeKdigits("1432219", 3) << endl;
    cout << removeKdigits("10200", 1) << endl;
    cout << removeKdigits("10", 2) << endl;
    cout << removeKdigits("10201", 2) << endl;
    cout << removeKdigits("212", 2) << endl;
}