#include "alg.h"

vector<int> sortArrayByParityII(vector<int> &A) {
    int left = 0, right = 1;
    for (; left < A.size() && right < A.size();) {
        if (A[left] % 2 == 0) {
            left += 2;
        } else if (A[right] % 2 == 1) {
            right += 2;
        } else {
            swap(A[left], A[right]);
        }
    }
    return A;
}

int main() {

}