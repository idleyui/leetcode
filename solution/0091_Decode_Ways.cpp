#include "alg.h"

bool isalpha(char c1, char c2) {
    return c1 == '1' || (c1 == '2' && c2 < '7');
}

int numDecodings(string s) {
    if (s.size() == 0) return 0;
    if (s[0] == '0') return 0;

    vector<int> dp(s.size() + 1, 1);
    for (int i = 2; i <= s.size(); i++) {
        if (isalpha(s[i - 2], s[i - 1])) {
            dp[i] = dp[i - 2];
            if (s[i - 1] != '0') dp[i] += dp[i - 1];
        } else if (s[i - 1] != '0') {
            dp[i] = dp[i - 1];
        } else {
            return 0;
        }
    }
    return dp[s.size()];
}

int main() {
    cout << numDecodings("0") << endl;
    cout << numDecodings("10") << endl;
    cout << numDecodings("01") << endl;
    cout << numDecodings("00") << endl;

}