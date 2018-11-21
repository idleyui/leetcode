class Solution {
public:
//     1. skip spaces
//     2. sign char?
//     3. skip nums
//     4. is e?
//     5. int after e?
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
};