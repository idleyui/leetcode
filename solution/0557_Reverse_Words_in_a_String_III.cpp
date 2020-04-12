#include "alg.h"

string reverseWords(string s) {
    int start = 0, end = 0;
    while (end < s.size()) {
        for (; s[end] != ' ' && end < s.size(); end++);
        reverse(s.begin() + start, s.begin() + end);
        start = end + 1;
        end = start;
    }
    return s;
}

int main() {

}