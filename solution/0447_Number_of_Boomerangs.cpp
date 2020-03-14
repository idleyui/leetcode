#include "alg.h"

//https://leetcode.com/problems/number-of-boomerangs/discuss/92861/Clean-java-solution%3A-O(n2)-166ms
int numberOfBoomerangs(vector<vector<int>> &points) {
    unordered_map<int, int> d2p;
    int cnt = 0;
    for (int i = 0; i < points.size(); i++) {
        for (int j = 0; j < points.size(); j++) {
            auto p1 = points[i], p2 = points[j];
            int d = (p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1]);
            d2p[d]++;
        }

        for (auto &kv: d2p) {
            cnt += kv.second * (kv.second - 1);
        }
        d2p.clear();
    }
    return cnt;
}

int main() {

}