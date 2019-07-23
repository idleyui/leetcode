#include "alg.h"

int lengthOfLastWord(string s) {
    int last_char_idx = s.size() - 1;
    for (; last_char_idx >= 0 && s[last_char_idx] == ' '; last_char_idx--);
    int len = 0;
    for (; last_char_idx >= 0 && s[last_char_idx] != ' '; last_char_idx--)len++;
    return len;
}
