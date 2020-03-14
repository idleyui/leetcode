#include "alg.h"

int compress(vector<char> &chars) {
    chars.push_back((char) 34);
    char last = chars[0];
    int new_i = 1;
    int cnt = 1;
    for (int i = 1; i < chars.size(); i++) {
        if (chars[i] == last) {
            cnt++;
            continue;
        }
        if (cnt != 1) {
            string cnt_s = to_string(cnt);
            for (char c: cnt_s) chars[new_i++] = c;
        }
        chars[new_i++] = chars[i];
        cnt = 1;
        last = chars[i];
    }
    return new_i - 1;
}

int main() {

}