#include "alg.h"

int evalRPN(vector<string> tokens) {
    int val;
    vector<int> nums;
    for (string s: tokens) {
        if (isdigit(s[0]) || s.size() > 1) {
            nums.push_back(stoi(s));
        } else {
            int tmp = 0, left = *(nums.end() - 2), right = *(nums.end() - 1);
            if (s == "+") {
                tmp = left + right;
            } else if (s == "-") {
                tmp = left - right;
            } else if (s == "*") {
                tmp = left * right;
            } else if (s == "/") {
                tmp = left / right;
            } else {
            }
            nums.pop_back();
            nums.pop_back();
            nums.push_back(tmp);
        }
    }
    return nums[0];
}

int main() {
    cout << evalRPN({"2", "1", "+", "3", "*"}) << endl;
    cout << evalRPN({"4", "13", "5", "/", "+"}) << endl;
    cout << evalRPN({"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"}) << endl;
}