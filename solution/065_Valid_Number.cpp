#include "alg.h"

bool isNumber(string s) {
    int pos = s.find_first_not_of(' ');

    if (s[pos] == '+' || s[pos] == '-') pos++;

    int point_cnt = 0;
    bool has_num = false;

    for (; pos < s.size(); pos++) {
        if (isdigit(s[pos])) has_num = true;
        else if (s[pos] == '.' && !point_cnt++)continue;
        else break;
    }

    if (!has_num) return false;
    if (pos == s.size()) return true;

    if (s[pos] == 'e') {
        pos++;
        if (s[pos] == '+' || s[pos] == '-') pos++;
        int buf = pos;
        for (; pos < s.size() && isdigit(s[pos]); pos++);
        if(pos == buf) return false;
    }
    for (; pos < s.size() && s[pos] == ' '; pos++);

    return pos == s.size();
}

int main() {
    vector<string> true_s = {"1", "1.2", " 2.1 ", " 2.1e1 ", " -2 ", "5e-1",};
    vector<string> false_s = {"abc", "1 a", " 1e",};
    for (const string &s: true_s) {
        if (!isNumber(s)) cout << s << endl;
    }
    for (const string &s: false_s) {
        if (isNumber(s)) cout << s << endl;
    }
}