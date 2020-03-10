#include "alg.h"

// https://leetcode.com/problems/ones-and-zeroes/discuss/95807/0-1-knapsack-detailed-explanation.
int findMaxForm(vector<string> &strs, int m, int n) {
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (string s: strs) {
        int zero = 0;
        for (char c: s) { if (c == '0') zero++; }
        int one = s.size() - zero;
        for (int i = m; i >= 0; i--) {
            if (zero > i) break;
            for (int j = n; j >= 0; j--) {
                if (one > j) break;
                dp[i][j] = max(dp[i][j], dp[i - zero][j - one] + 1);
            }
        }
    }
    return dp.back().back();
}

int main() {

}