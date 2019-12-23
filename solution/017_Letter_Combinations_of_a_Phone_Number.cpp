#include "alg.h"

vector<string> letterCombinations(string digits) {
    if (digits.size() == 0)return {};
    string arr[9]{"*", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> result = {""};
    for (char c: digits) {
        int num = c - '1';
        vector<string> new_result = {};
        for (char c1: arr[num]) {
            for (string rt: result) {
                new_result.push_back(rt + c1);
            }
        }
        result = new_result;
    }
    return result;
}


int main() {
    string s = "12345";
    vector<string> v1 = letterCombinations(s);
    cout << v1.size();
    print_container(v1);
}