#include "alg.h"

string replaceSpace(string s) {
    int cnt = 0;
    for (char c: s) {
        if (c == ' ') cnt++;
    }

    string new_s(s.size() + cnt * 2, ' ');
    int i = 0;
    for (char c: s) {
        if (c == ' ') {
            new_s[i++] = '%';
            new_s[i++] = '2';
            new_s[i++] = '0';
        } else {
            new_s[i++] = c;
        }
    }
    return new_s;
}

int main() {

}