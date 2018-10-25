#include "alg.h"

string convert(string s, int numRows) {
    if (numRows == 1)return s;
    string result = "";
    int total = (numRows - 1) * 2;
    for (int i = 0; i < numRows; i++) {
        result += s[i];
        int buf = (numRows - i - 1) * 2;
        buf = buf == 0 ? total : buf;
        for (int j = i + buf; j < s.size(); j += buf) {
            result += s[j];
            buf = buf == total ? buf : total - buf;
            cout << j << ' ';
        }
    }
    return result;
}

int main() {
    cout << convert("PAYPALISHIRING", 3);
}