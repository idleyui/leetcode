#include "alg.h"


int dist(const vector<int> &p, int r0, int c0) {
    return abs(p[0] - r0) + abs(p[1] - c0);
}

// Sort
vector<vector<int>> allCellsDistOrder_1(int R, int C, int r0, int c0) {
    vector<vector<int>> rt(R * C, vector<int>(2, 0));
    int pos = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            rt[pos][0] = i;
            rt[pos][1] = j;
            pos++;
        }
    }
    // add this in leetcode
    sort(rt.begin(), rt.end(), [r0, c0](const vector<int> &v1, const vector<int> &v2) {
        return dist(v1, r0, c0) < dist(v2, r0, c0);
    });
    return rt;
}

// BFS without visited
vector<vector<int>> allCellsDistOrder_2(int R, int C, int r0, int c0) {
    int N = R * C;
    vector<vector<int>> rt(N, {r0, c0});
    int l = 0, r = 1;
    while (r < N) {
        int p = r;
        for (int i = l; i < r; i++) {
            auto point = rt[i];
            if (point[0] > 0 && point[0] <= r0) { rt[p++] = {point[0] - 1, point[1]}; }
            if (point[0] < R - 1 && point[0] >= r0) { rt[p++] = {point[0] + 1, point[1]}; }
            if (point[0] != r0) continue;
            if (point[1] > 0 && point[1] <= c0) { rt[p++] = {point[0], point[1] - 1}; }
            if (point[1] < C - 1 && point[1] >= c0) { rt[p++] = {point[0], point[1] + 1}; }
        }
        l = r;
        r = p;
    }
    return rt;
}

int dist(int r, int c, int r0, int c0) {
    return abs(r - r0) + abs(c - c0);
}

// counting sort
//https://leetcode.com/problems/matrix-cells-in-distance-order/discuss/278986/4ms-O(n)-Java-Counting-Sort-()-Solution
vector<vector<int>> allCellsDistOrder_3(int R, int C, int r0, int c0) {
    vector<int> cnt(R * C + 1, 0);
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cnt[dist(i, j, r0, c0) + 1]++;
        }
    }

    for (int i = 1; i < cnt.size(); i++) {
        cnt[i] += cnt[i - 1];
    }

    vector<vector<int>> rt(R * C, {0, 0});
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            int dist_val = dist(i, j, r0, c0);
            rt[cnt[dist_val]] = {i, j};
            cnt[dist_val]++;
        }
    }
    return rt;
}

int main() {
}