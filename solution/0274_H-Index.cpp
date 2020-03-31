#include "alg.h"

static bool cmp(const int &a, const int &b) {
    return a > b;
}

int hIndex(vector<int> &citations) {
    sort(citations.begin(), citations.end(), cmp);
    int i = 0;
    for (; i < citations.size() && citations[i] > i; i++);
    return i;
}

int main() {

}