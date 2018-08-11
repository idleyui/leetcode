#include "alg.h"

// discards whitespace
// plus or minus sign
// additional characters after number is ok, before is invalid

int myAtoi(string str) {
    // discards whitespace
    size_t whitespace = str.find_first_not_of(' ');
    str = whitespace == string::npos ? str : str.substr(whitespace);

    // set sign
    char sign = '+';
    if (str[0] == '-' || str[0] == '+') {
        sign = str[0];
        str = str.substr(1);
    } else if (isdigit(str[0])) sign = '+';
    else return 0;

    // remove additional characters after number
    int i = 0;
    for (; i < str.size() && isdigit(str[i]); i++);
    str = str.substr(0, i);

    // convert number
    int result = 0;
    for (i = 0; i < str.size(); i++) {
        int buf = result;
        result += pow(10.0, (double) i) * (str[str.size() - 1 - i] - '0');
        if (result < buf)
            return sign == '+' ? INT_MAX : INT_MIN;
    }

    return sign == '+' ? result : -result;
}

int main() {
    string arr[] = {"123", "+1234", "-932",
                    "", "  ",
                    "233 ckje", " -c324", "  ijden",
                    "32948903795434", "00000", "2147483648"};
    for (string s: arr) {
        cout << s << ":" << myAtoi(s) << endl;
    }
    int a = 2147483648;
    cout << a;
}