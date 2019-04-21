#include "alg.h"

vector<int> advantageCount(vector<int> A, vector<int> B) {
    sort(A.begin(), A.end());
    vector<int> C = B;
    sort(B.begin(), B.end());
    unordered_map<int, vector<int>> B2A;
    int i = 0, j = 0, pr = A.size() - 1;
    while (i < A.size()) {
        if (A[i] > B[j]) {
            if(B2A.count(B[j])) B2A[B[j]].push_back(A[i]);
            else B2A[B[j]] = {A[i]};
            i++;
            j++;
        } else {
            if(B2A.count(B[pr]))B2A[B[pr--]].push_back(A[i]);
            else B2A[B[pr--]] = {A[i]};
            i++;
        }
    }
    i = 0;
    for (int &bi: C) {
        A[i++] = B2A[bi].back();
        B2A[bi].pop_back();
    }
    return A;
}

int main() {
    print_container(advantageCount({2, 7, 11, 15}, {1, 10, 4, 11}));
    print_container(advantageCount({12, 24, 8, 32}, {13, 25, 32, 11}));
    print_container(advantageCount({12, 24, 8, 32}, {13, 25, 9, 33}));
    print_container(advantageCount({12, 24, 8, 32}, {32, 32, 32, 33}));
}