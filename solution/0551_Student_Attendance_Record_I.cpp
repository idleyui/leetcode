#include "alg.h"


bool checkRecord(string s) {
    int acnt = 0, lcnt = 0;
    for (char c: s) {
        if (c == 'A') {
            acnt++;
            lcnt = 0;
            if (acnt > 1) return false;
        } else if (c == 'L') {
            lcnt++;
            if (lcnt > 2) return false;
        } else {
            lcnt = 0;
        }
    }
    return true;
}

int main() {

}