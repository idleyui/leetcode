#include "alg.h"

string convertToBase7(int num) {
    if (!num) return "0";
    bool negative = false;
    if (num < 0) {
        num = -num;
        negative = true;
    }
    string ans = "";
    while (num) {
        ans = to_string(num % 7) + ans;
        num /= 7;
    }
    return negative ? "-" + ans : ans;

}

int main() {

}