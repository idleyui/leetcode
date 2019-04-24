#include "alg.h"

vector<int> findMinHeightTrees(int n, vector<pair<int, int>> edges) {
    vector<vector<int>> neibors(n, vector<int>());
    vector<int> neibor_cnt(n, 0);
    vector<bool> visited = vector<bool>(n, false);
    for (auto &p: edges) {
        neibors[p.first].push_back(p.second);
        neibors[p.second].push_back(p.first);
        neibor_cnt[p.first]++;
        neibor_cnt[p.second]++;
    }

    int cnt = 0;
    vector<int> leaf;
    while (cnt < n - 2) {
        leaf.clear();
        for (int i = 0; i < neibors.size(); i++) {
            if (neibor_cnt[i] == 1) {
                leaf.push_back(i);
            }
        }
        for (auto i: leaf) {
            neibor_cnt[i] = -1;
            for (auto neibor: neibors[i]) {
                neibor_cnt[neibor] -= 1;
            }
            cnt++;
        }
    }


    vector<int> result;
    for (int i = 0; i < n; ++i) { if (neibor_cnt[i] >= 0)result.push_back(i); }

    return result;
}

int main() {
    print_container(findMinHeightTrees(2, {{1, 0}}));
    print_container(findMinHeightTrees(4, {{1, 0},
                                           {1, 2},
                                           {1, 3}}));
    print_container(findMinHeightTrees(6, {{0, 3},
                                           {1, 3},
                                           {2, 3},
                                           {4, 3},
                                           {5, 4}}));
    print_container(findMinHeightTrees(7, {{0, 3},
                                           {1, 3},
                                           {6, 3},
                                           {6, 4},
                                           {2, 3},
                                           {5, 4}}));
    print_container(findMinHeightTrees(8, {{0, 1},
                                           {1, 2},
                                           {2, 3},
                                           {0, 4},
                                           {4, 5},
                                           {4, 6},
                                           {6, 7}}));
}