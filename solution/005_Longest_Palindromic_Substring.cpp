#include "alg.h"

// approach 1: Longest Common Substring
bool palind(string s) {
    for (int i = 0; i < s.size() / 2; i++) {
        if (s[i] != s[s.size() - 1 - i])return false;
    }
    return true;
}

string longestPalindrome_lcs(const string &s) {
    if (s.size() == 0)return "";

    string rs = s;
    for (int i = 0; i < rs.size() / 2; i++) swap(rs[i], rs[rs.size() - 1 - i]);

    // matrix[i][j] != 0 means s[i] == s[j], use matrix[i][j] = matrix[i-1][j-1]+1 to log str length
    vector<vector<int>> matrix(s.size(), vector<int>(s.size(), 0));
    int max = 0, max_i = 0;
    for (int i = 0; i < s.size(); i++) {
        for (int j = 0; j < s.size(); j++) {
            if (rs[j] == s[i]) {
//                if (i > 0 && j > 0 matrix[i - 1][j - 1] != 0)
                if (i > 0 && j > 0)
                    matrix[i][j] = matrix[i - 1][j - 1] + 1;
                else
                    matrix[i][j] = 1;
                if (matrix[i][j] > max && palind(s.substr(i - matrix[i][j] + 1, matrix[i][j]))) {
                    max = matrix[i][j];
                    max_i = i - max + 1;
                }
            }
        }
    }
    return s.substr(max_i, max);
}

// approach 3 Dynamic Programming
string longestPalindrome_dp(const string &s) {
    if (s.size() == 0)return "";
    vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));

    int max = 1, max_i = 0;
    for (int i = 0; i < s.size(); i++) dp[i][i] = 1;

    for (int i = 0; i < s.size() - 1; ++i) {
        dp[i][i + 1] = s[i] == s[i + 1];
        if (dp[i][i + 1]) {
            max = 2;
            max_i = i;
        }
    }

    for (int len = 1; len <= s.size(); len++) {
        for (int i = 1; i < s.size() - len; ++i) {
            if (dp[i][i + len - 1] && s[i - 1] == s[i + len]) {
                dp[i - 1][i + len] = 1;
                max = len + 2;
                max_i = i - 1;
            }
        }
    }
    return s.substr(max_i, max);
}

// approach 4: expand around center
int expand(string s, int l, int r) {
    for (; l >= 0 && r < s.size() && s[l] == s[r]; l--, r++);
    return r - l - 1;
}

string longestPalindrome_exp(const string &s) {
    if (s.size() == 0) return "";
    int start = 0, end = 0;
    for (int i = 0; i < s.size(); i++) {
        int len1 = expand(s, i, i);
        int len2 = expand(s, i, i + 1);
        int len = max(len1, len2);
        if (len > end - start + 1) {
            start = i - (len - 1) / 2;
            end = i + len / 2;
        }
    }
    return s.substr(start, end - start + 1);
}

int main() {
//    assert(longestPalindrome_lcs("a") == "a");
//    assert(longestPalindrome_lcs("abab") == "aba");
//    assert(longestPalindrome_lcs("abba") == "abba");
//    assert(longestPalindrome_exp("a") == "a");
//    assert(longestPalindrome_exp("abab") == "aba");
//    assert(longestPalindrome_exp("abba") == "abba");
//    assert(longestPalindrome_dp("a") == "a");
    cout << longestPalindrome_dp("a");
//    cout << longestPalindrome_dp("abab");
    cout << longestPalindrome_dp("abba");
//    assert(longestPalindrome_dp("abab") == "aba");
//    assert(longestPalindrome_dp("abba") == "abba");
}