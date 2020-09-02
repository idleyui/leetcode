#include "alg.h"

vector<int> printNumbers(int n) {
    int MAX = 1;
    for (int i = 0; i < n; i++) {
        MAX *= 10;
    }

    vector<int> ans;
    ans.reserve(MAX+10);
    for (int i = 1; i < MAX; i++) {
        ans.push_back(i);
    }
    return ans;
}

int main() {

}