// online judge: https://www.lintcode.com/problem/sort-integers
#include "alg.h"

// 1. bubble sort
void bubble_sort(vector<int> &A) {
    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < A.size() - 1 - i; j++) {
            if (A[j] > A[j + 1]) swap(A[j], A[j + 1]);
        }
    }
}

void bubble_sort_early_stop(vector<int> &A) {
    bool bubble = false;
    for (int i = 0; i < A.size(); i++) {
        bubble = false;
        for (int j = 0; j < A.size() - 1 - i; j++) {
            if (A[j] > A[j + 1]) {
                swap(A[j], A[j + 1]);
                bubble = true;
            }
        }
        if (!bubble) break;
    }
}

// 2. selection sort
void selection_sort(vector<int> &A) {
    for (int i = 0; i < A.size(); i++) {
        int base = i;
        for (int j = i + 1; j < A.size(); j++) {
            if (A[j] < A[i]) swap(A[i], A[j]);
        }
    }
}

// 3. insertion sort
void insertion_sort(vector<int> &A) {
    for (int i = 0; i < A.size() - 1; i++) {
        int j = i + 1, tmp = A[j];
        for (; j > 0 && tmp < A[j - 1]; j--) A[j] = A[j - 1];
        A[j] = tmp;
    }
}

// binary insertion sort
void insertion_sort(vector<int> &A) {
    for (int i = 0; i < A.size() - 1; i++) {
        int l = 0, h = i + 1, v = A[i + 1];
        while (l < h) {
            int mid = l + (h - l) / 2;
            if (A[mid] == v) {
                l = mid;
                break;
            } else if (A[mid] < v) { l = mid + 1; }
            else { h = mid; }
        }
        for (int j = i; j >= l; j--) A[j + 1] = A[j];
        A[l] = v;
    }
}



// https://stackoverflow.com/questions/22504837/how-to-implement-quick-sort-algorithm-in-c
void sortIntegers(vector<int> &A) {
    q_sort(A, 0, A.size() - 1);
}

// heap sort
void heapify(vector<int> &A, int l, int h) {
    int parent = l;
    int child = parent * 2 + 1;
    while (child <= h) {
        if (child + 1 <= h && A[child + 1] > A[child]) child++;
        if (A[parent] > A[child]) return;
        else {
            swap(A[parent], A[child]);
            parent = child;
            child = parent * 2 + 1;
        }
    }
}

void heap_sort(vector<int> &A) {
//    build max heap
    for (int i = A.size() / 2 - 1; i >= 0; i--) {
        heapify(A, i, A.size() - 1);
    }
//    sort
    for (int i = A.size() - 1; i < A.size(); i++) {
        swap(A[i], A[0]);
        heapify(A, 0, A.size() - 1);
    }
}

// shell sort

// counting sort
// A between [0-100]
void counting_sort(vector<int> &A) {

}

// radix sort

// bucket sort

int main() {

}