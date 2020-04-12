#include "alg.h"

string reverseStr(string s, int k) {
    bool r = true;
    for (int i = 0; i < s.size(); i += k) {
        if (r) {
            reverse(s.begin() + i, (i + k) >= s.size() ? s.end() : s.begin() + i + k);
        }
        r = !r;
    }
    return s;
}

int main() {

}