#include "alg.h"

void reverse(vector<int> &A, int l, int h) {
    while (l < h) {
        swap(A[l++], A[h--]);
    }
}

// flip max in the end
vector<int> pancakeSort(vector<int> &A) {
    vector<int> flips;
    for (int i = A.size(); i >= 1; i--) {
        int max_i = 0;
        for (; A[max_i] != i; max_i++);
        flips.push_back(max_i + 1);
        flips.push_back(i);
        reverse(A, 0, max_i);
        reverse(A, 0, i - 1);
    }
    return flips;
}

int main() {

}