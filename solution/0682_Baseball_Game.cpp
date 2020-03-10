#include "alg.h"

int calPoints(vector<string> ops) {
    vector<int> stk;
    for (auto &s: ops) {
        if (s == "C") {
            stk.pop_back();
        } else if (s == "D") {
            stk.push_back(stk.back() * 2);
        } else if (s == "+") {
            stk.push_back(stk.back() + (*(stk.end() - 2)));
        } else {
            stk.push_back(stoi(s));
        }
    }
    return accumulate(stk.begin(), stk.end(), 0);
}

int main() {
    cout << calPoints({"1", "2", "3", "D", "C", "+"});
    cout << calPoints({"5", "-2", "4", "C", "D", "9", "+", "+"});
    cout << calPoints({"5", "2", "C", "D", "+"});
}