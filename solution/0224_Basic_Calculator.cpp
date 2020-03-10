#include "alg.h"

void cal(vector<int> &nums, vector<char> &opers) {
    int right = nums.back();
    nums.pop_back();
    int left = nums.back();
    nums.pop_back();
    auto pre_oper = opers.back();
    if (pre_oper == '+') { nums.push_back(left + right); }
    if (pre_oper == '-') { nums.push_back(left - right); }
    if (pre_oper == '*') { nums.push_back(left * right); }
    if (pre_oper == '/') { nums.push_back(left / right); }
    opers.pop_back();
}

int calculate(string s) {
    s = s.substr(0, s.find_last_not_of(' ') + 1);
    vector<int> nums;
    vector<char> opers = {'#'};
    unordered_map<char, int> prior{{'#', 0},
                                   {'+', 1},
                                   {'-', 1},
                                   {'*', 2},
                                   {'/', 2},
                                   {'(', 0},
                                   {')', 0}};
    int num = 0;
    int pre_isdigit = 0;//0-oper,1-num,2-(,3-)
    char sign = '+';
    for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        if (c == ' ') continue;
        if (isdigit(c)) {
            num = num * 10 + (c - '0');
            pre_isdigit = 1;
        } else {
            if (c == '(') {
                opers.push_back(c);
                pre_isdigit = 2;
            } else {
                if (pre_isdigit == 1) {
                    num = sign == '+' ? num : -num;
                    nums.push_back(num);
                    sign = '+';
                    num = 0;
                }
                if (c == ')') {
                    while (opers.back() != '(') {
                        cal(nums, opers);
                    }
                    opers.pop_back();
                    pre_isdigit = 3;
                } else {
                    if (pre_isdigit == 0) {
                        sign = c;
                        continue;
                    }
                    while (prior[c] <= prior[opers.back()]) {
                        cal(nums, opers);
                    }
                    opers.push_back(c);
                    pre_isdigit = 0;
                }
            }
        }
    }
    if (pre_isdigit == 1) { nums.push_back(num); }
    while (opers.size() > 1) { cal(nums, opers); }
    return nums[0];
}

int main() {
//    cout << calculate("1 + 1") << endl;
//    cout << calculate(" 2-1 + 2 ") << endl;
//    cout << calculate("2*(1+2)") << endl;
//    cout << calculate("1+ -2 +1") << endl;
    cout << calculate("(1+(4+5+2)-3)+(6+8)") << endl;
    cout << calculate(" ( 1 +( 4+  -5+2  )-3)+(1+(6+8))") << endl;
}