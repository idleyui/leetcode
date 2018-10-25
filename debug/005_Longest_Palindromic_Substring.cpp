#include "alg.h"

bool isPalind(string s) {
    for (int i = 0; i < s.size() / 2; i++) {
        if (s[i] != s[s.size() - 1 - i])return false;
    }
    return true;
}

string longestPalindrome(string s) {
    if (s.size() == 0)return "";
    string rs = s;
    for (int i = 0; i < rs.size() / 2; i++) swap(rs[i], rs[rs.size() - 1 - i]);
    int matrix[s.size()][s.size()] = {}, max = 0, max_i = 0;
    for (int i = 0; i < s.size(); i++) {
        for (int j = 0; j < s.size(); j++) {
            if (rs[j] == s[i]) {
                if (i > 0 && j > 0 && matrix[i - 1][j - 1] != 0)
                    matrix[i][j] = matrix[i - 1][j - 1] + 1;
                else
                    matrix[i][j] = 1;
                if (matrix[i][j] > max && isPalind(s.substr(i - matrix[i][j] + 1, matrix[i][j]))) {
                    max = matrix[i][j];
                    max_i = i - max + 1;
                }
            }
        }
    }
    return s.substr(max_i, max);
}

int main() {
    cout << longestPalindrome("a");
}