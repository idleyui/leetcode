#include "alg.h"

vector<string> letterCombinations(string digits) {
    if (digits.size() == 0)return {};
    string arr[9]{"*", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> v;
    for (char c: arr[digits[0] - '1']) v.push_back(string(1, c));
    for (int i = 1; i < digits.size(); ++i) {
        string append = arr[digits[i] - '1'];
        vector<string> v1;
        for (char c: append) {
            for (string s: v) {
                s.push_back(c);
                v1.push_back(s);
            }
        }
        v.clear();
        v.assign(v1.begin(), v1.end());
    }
    return v;
}

int main() {
    string s = "12345";
    vector<string> v1 = letterCombinations(s);
    cout << v1.size();
    print_container(v1);
}