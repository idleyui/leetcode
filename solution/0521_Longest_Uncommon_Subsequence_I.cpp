#include "alg.h"

int findLUSlength(string a, string b) {
    if (a.size() < b.size()) return findLUSlength(b, a);
    if (a.size() > b.size()) return a.size();
    if (a == b) return -1;
    return a.size();
}

int main() {

}