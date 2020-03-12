#include "alg.h"

// capital and lower case !
bool isVowel(char c) {
    c = tolower(c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

string reverseVowels(string s) {
    for (int l = 0, h = s.size() - 1; l < h;) {
        if (isVowel(s[l]) && isVowel(s[h])) {
            swap(s[l++], s[h--]);
        }
        if (!isVowel(s[l])) l++;
        if (!isVowel(s[h])) h--;
    }
    return s;
}

int main() {

}