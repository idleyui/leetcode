#include "alg.h"


string nextPermutation(string s) {
    int i = s.size()-2;
    for(; i >= 0 && s[i] >= s[i+1]; i--);
    if(i < 0) { return s; }
    int j = s.size()-1;
    for(; j > 0 && s[j] <= s[i]; j--);
    swap(s[i], s[j]);
    reverse(s.begin() + i + 1, s.end());
    return s;
}

int nextGreaterElement(int n) {
    string s = to_string(n);
    string new_s = nextPermutation(s);
    if (s == new_s) return -1;
    long long next_gt = stoll(new_s);
    return next_gt > INT_MAX ? -1:next_gt;
}

int main() {

}