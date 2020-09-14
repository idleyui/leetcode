#include "alg.h"

// left / right pointer
//int partition_hoare(vector<int> &v, int l, int h) { int val = v[l];
//    while (l < h) {
//        while (l < h && v[l] < val)l++;
//        while (l < h && v[h] >= val)h--;
//        if (l < h)swap(v[l], v[h]);
//    }
//    return l-1;
//}
//
//void qsort_hoare(vector<int> &v, int l, int h) {
//    if (l >= h)return;
//    int m = partition_hoare(v, l, h);
//    qsort_hoare(v, l, m);
//    qsort_hoare(v, m + 1, h);
//}

int partition_hoare(vector<int> &v, int l, int h) {
    int val = v[l];
    l = l - 1, h = h + 1;
    while (l < h) {
        do l++; while (v[l] < val);
        do h--; while (v[h] > val);
        if (l < h)swap(v[l], v[h]);
    }
    return h;
}

void qsort_hoare(vector<int> &v, int l, int h) {
    if (l >= h)return;
    int m = partition_hoare(v, l, h);
    qsort_hoare(v, l, m);
    qsort_hoare(v, m + 1, h);
}


int partition(vector<int> &v, int l, int h) {
    int val = v[l];
    l = l - 1, h = h + 1;
    while (l < h) {
        do l++; while (v[l] < val);
        do h--; while (v[h] > val);
        if (l < h)swap(v[l], v[h]);
    }
    return h;
}

void qsort(vector<int> &v, int l, int h) {
    if (l >= h)return;
    int m = partition(v, l, h);
    qsort(v, l, m);
    qsort(v, m + 1, h);
}


// slow / fast pointer
int partition_lomuto(vector<int> &A, int l, int h) {
    int flag = A[l], left = l;
    for (int right = left + 1; right <= h; right++) {
        if (A[right] <= flag) swap(A[++left], A[right]);
    }
    swap(A[l], A[left]);
    return left;
}

void qsort_lomuto(vector<int> &A, int l, int h) {
    if (l >= h) return;
    int r = partition_lomuto(A, l, h);
    qsort_lomuto(A, l, r - 1);
    qsort_lomuto(A, r + 1, h);
}


int main() {
//    vector<int> A = {26, 71, 35, 51, 30, 73, 30, -2, 58, -4, 46, 41, 23, 54, 72, 56, 70, -4, 66, 4, 54, 40, 15, 28, 43, -1, 80, 1, 75, 11, 24, 58, 51, 67, 27, 69, 5, 28, 80, 18, 68, 43, 54, 47, 72, 36, 71, 19, 19, 80, 40, 25, 66, 51, 35, 70, 27, 35, 44, 60, 72, 40, 53, 37, 26, 3, 75, -8, 53, 52, 16, 60, 18, 14, 22, 67, 9, 12, 60, 60};

    vector<int> A = {19, -10, -2, 40, 3, 36, 57, 25, 66, 51, 5, 40, -8, 43, 9, -5, 0, 4, 55, 28, 63, 67, -2, 35, 57, 0,
                     0, 30, 17, 55, 22, 34, -4, 42, 57, 52, 4, 65, 6, -2, 8, 12, 31, 43, 26, 34, 31, 19, -3, 36, 34, 11,
                     58, 23, 13, 7, 17, 10, 33, -5, 10, 53, 14, 56, 18, 8, -6, -2, 37, 7};
//    vector<int> A = {3,2,1,4,5};
    qsort_hoare(A, 0, A.size() - 1);
    print_container(A);
}