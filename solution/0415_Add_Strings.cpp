#include "alg.h"

string addStrings(string num1, string num2) {
    string ans = "";
    int carry = 0;
    for (int i = num1.size() - 1, j = num2.size() - 1; i >= 0 || j >= 0 || carry; i--, j--) {
        int sum = (i >= 0 ? num1[i] - '0' : 0) + (j >= 0 ? num2[j] - '0' : 0) + carry;
        carry = sum / 10;
        ans = (char) ('0' + sum % 10) + ans;
    }
    return ans;
}

int main() {

}