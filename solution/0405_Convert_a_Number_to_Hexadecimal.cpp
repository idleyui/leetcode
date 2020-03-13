#include "alg.h"

//
string toHex_1(int num) {
    if (num == 0) return "0";
    string hex = "0123456789abcdef";

    if (num < 0) {
        string ans = toHex_1(num - (1 << 31));
        if (ans.size() < 8) {
            ans = string(8 - ans.size() - 1, '0') + ans;
            ans = '8' + ans;
        } else {
            ans[0] = hex[ans[0] - '0' + 8];
        }
        return ans;
    }

    string ans = "";
    while (num > 0) {
        ans = hex[num % 16] + ans;
        num /= 16;
    }
    return ans;
}

// bit
string toHex_2(int num) {
    if (num == 0) return "0";
    string hex = "0123456789abcdef";
    string ans = "";
    for (int i = 0; i < 8; i++) {
        int cur = num & 15;
        ans = hex[cur] + ans;
        num >>= 4;
        if(num == 0)    break;
    }
    return ans;
}

int main() {

}