#include "alg.h"

bool check(int x) { return true; }


// |-------AB---------|
// find B
int binary_searchA(int l, int r) {
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    return l;
}

// |-------AB---------|
// find A
int binary_searchB(int l, int r) {
    while (l < r) {
        int mid = l + (r + 1 - l) / 2;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    return l;
}

int main() {

}