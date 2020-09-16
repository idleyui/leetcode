#include "alg.h"

bool check(int x) { return true; }


// |-------AB---------|   find B
// |-----------------A|B  find A
int binary_searchB(int l, int r) {
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    return l;
}

// |-------AB---------|
// find A
int binary_searchA(int l, int r) {
    while (l < r) {
        int mid = l + (r + 1 - l) / 2;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    return l;
}

// example: sorted array [1,2,3,4,4,5] find >= target
int binary_searchB(vector<int> &A, int target) {
    int l = 0, r = A.size() - 1;
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (A[mid] < target) l = mid + 1;
        else r = mid;
    }
    return l;
}

// example: sorted array [1,2,3,4,4,5] find <= target
int binary_searchA(vector<int> &A, int target) {
    int l = 0, r = A.size() - 1;
    while (l < r) {
        int mid = l + (r + 1 - l) / 2;
        if (A[mid] <= target) l = mid;
        else r = mid - 1;
    }
    return l;
}

int main() {
    vector<int> A = {1, 2, 3, 4, 4, 5};
    cout << binary_searchB(A, 4);
    cout << binary_searchB(A, 5);
    cout << binary_searchB(A, 6);
    cout << binary_searchA(A, 2);
    cout << binary_searchA(A, 1);
    cout << binary_searchA(A, 0);
}