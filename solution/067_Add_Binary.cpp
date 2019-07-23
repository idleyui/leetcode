#include "alg.h"

string addBinary(string a, string b) {
    int ai = a.size() - 1;
    int bi = b.size() - 1;
    string result = "";
    int carry = 0;
    while (ai >= 0 || bi >= 0 || carry) {
        int sum = (ai >= 0 ? (a[ai] - '0') : 0) + (bi >= 0 ? (b[bi] - '0') : 0) + carry;
        result = (sum % 2 ? '1' : '0') + result;
        carry = sum / 2;
        ai -= 1;
        bi -= 1;
    }
    return result;
}
