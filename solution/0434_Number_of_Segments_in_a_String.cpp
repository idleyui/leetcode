#include "alg.h"

int countSegments(string s) {
    int cnt = 0;
    bool last_is_alpha = false;
    for (char c: s) {
        if (c != ' ') last_is_alpha = true;
        else if (last_is_alpha) {
            last_is_alpha = false;
            cnt++;
        }
    }
    return last_is_alpha ? cnt + 1 : cnt;
}

int main() {

}