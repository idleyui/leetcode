#include "alg.h"

static bool cmp(vector<int> &p1, vector<int> &p2) {
    return p1[0] * p1[0] + p1[1] * p1[1] > p2[0] * p2[0] + p2[1] * p2[1];
}

// Solution 1: NlogK heap
vector<vector<int>> kClosest_1(vector<vector<int>> &points, int K) {
    make_heap(points.begin(), points.end(), cmp);
    vector<vector<int>> ans;
    ans.reserve(K);
    for (int i = 0; i < K; i++) {
        pop_heap(points.begin(), points.end(), cmp);
        ans.push_back(points.back());
        points.pop_back();
    }
    return ans;
}

static bool cmp_2(vector<int> &p1, vector<int> &p2) {
    return p1[0] * p1[0] + p1[1] * p1[1] < p2[0] * p2[0] + p2[1] * p2[1];
}

// Solution 2: sort
vector<vector<int>> kClosest_2(vector<vector<int>> &points, int K) {
    sort(points.begin(), points.end(), cmp_2);
    return vector<vector<int>>(points.begin(), points.begin() + K);
}

static int cmp_3(vector<int> &p1, vector<int> &p2) {
    return p1[0] * p1[0] + p1[1] * p1[1] - p2[0] * p2[0] + p2[1] * p2[1];
}

int helper(vector<vector<int>> &A, int l, int h) {
    vector<int> p = A[0];
    while (l < h) {
        while (l < h && cmp_2(A[l], p) >= 0) r--;
        A[l] = A[h];
        while (l < h && cmp_2(A[l], p) <= 0) l++;
        A[h] = A[l];
    }
    A[l] = p;
    return l;
}

// https://leetcode.com/problems/k-closest-points-to-origin/discuss/220235/Java-Three-solutions-to-this-classical-K-th-problem.
vector<vector<int>> kClosest_3(vector<vector<int>> &points, int K) {
    int l = 0, h = points.size() - 1;
    while (l < h) {
        int mid = helper(points, l, h);
        if (mid == K) {
            break;
        } else if (mid < K) {
            l = mid + 1;
        } else {
            h = mid - 1;
        }
    }
    return vector<vector<int>>(points.begin(), points.begin() + K);
}

int main() {

}