#include "alg.h"

int main() {
    set<unordered_multiset<int>> s;
    unordered_multiset<int> ums({1});

//    set<vector<int>> s;
//    vector<int> ums({1});
    s.insert(ums);
}