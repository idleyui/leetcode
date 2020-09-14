#include "alg.h"


void merge(vector<int> &A, vector<int> &rt, int lo, int hi) {
    int mid = lo + (hi - lo) / 2, i = lo, j = mid + 1, k = lo;
    while (i <= mid && j <= hi) {
        if (A[i] <= A[j]) rt[k++] = A[i++];
        else rt[k++] = A[j++];
    }
    while (i <= mid) rt[k++] = A[i++];
    while (j <= hi) rt[k++] = A[j++];
    for (int idx = lo; idx <= hi; idx++) A[idx] = rt[idx];
}

void merge_sort(vector<int> &A, vector<int> &rt, int l, int h) {
    if (l >= h) return;
    int mid = l + (h - l) / 2;
    merge_sort(A, rt, l, mid);
    merge_sort(A, rt, mid + 1, h);
    merge(A, rt, l, h);
}

void merge_sort(vector<int> &A) {
    vector<int> rt(A.size(), 0);
    merge_sort(A, rt, 0, rt.size() - 1);
}

int main() {

}