#include "alg.h"

// approach 1:
string convert(string s, int numRows) {
    if (numRows == 1) return s;
    string rt = "";

    vector<string> rows(numRows, "");
    bool down = false;

    int i = 0;
    for (char c: s) {
        if (i == 0 || i == numRows - 1) down = !down;
        rows[i] += c;
        i = down ? i + 1 : i - 1;
    }

    for (string s: rows) rt += s;
    return rt;
}

// approach 2:
string convert2(string s, int numRows) {
    if (numRows == 1) return s;

    string rt = "";
    int cycle_len = 2 * numRows - 2;

    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j + i < s.size(); j += cycle_len) {
            rt += s[i + j];
            if (i != 0 && i != numRows - 1 && j + cycle_len - i < s.size())
                rt += s[j + cycle_len - i];
        }
    }

    return rt;
}


int main() {
    cout << convert("PAYPALISHIRING", 3);
    cout << convert2("PAYPALISHIRING", 3);
}