#include "alg.h"

// hoare partition
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


// hoare partition (use while)
int partition_hoare_while(vector<int> &v, int l, int h) {
    int val = v[l];
//    wrong implementation, {1, 2, 1} the mid 2 won't be check
//    while (l < h) {
    while (true) {
        while (v[l] < val)l++;
        while (v[h] > val)h--;
        if (l < h)swap(v[l++], v[h--]);
        else break;
    }
    return h;
}



void qsort_hoare_while(vector<int> &v, int l, int h) {
    if (l >= h)return;
    int m = partition_hoare_while(v, l, h);
    qsort_hoare_while(v, l, m);
    qsort_hoare_while(v, m + 1, h);
}

// lomuto partition
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
//    vector<int> A = {3, 2, 1, 4, 5};
    vector<int> A = {1, 2, 1};
    qsort_hoare_while(A, 0, A.size() - 1);
    print_container(A);
}