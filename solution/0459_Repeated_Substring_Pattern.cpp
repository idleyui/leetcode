#include "alg.h"

// https://leetcode.com/problems/repeated-substring-pattern/discuss/94334/Easy-python-solution-with-explaination
bool repeatedSubstringPattern(string s) {
    string ss = s + s;
    ss = ss.substr(1, ss.size() - 2);
    return ss.find(s) != string::npos;
}

int main() {

}