#include "alg.h"

void max_heapify_r(vector<int> &A, int i) {
    int left = i * 2 + 1, right = left + 1, largest = i;
    if (left < A.size() && A[left] > A[i]) largest = left;
    if (right < A.size() && A[right] > A[largest]) largest = right;
    if (largest != i) {
        swap(A[i], A[largest]);
        max_heapify(A, largest);
    }
}

void max_heapify(vector<int> &A, int i) {
    for (int child = i * 2 + 1; child < A.size();) {
        if (child + 1 < A.size() && A[child + 1] > A[child]) child += 1;
        if (A[i] >= A[child]) return;
        swap(A[i], A[child]);
        i = child;
        child = child * 2 + 1;
    }
}


int main() {

}