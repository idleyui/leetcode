#include "alg.h"

int partitionDisjoint(vector<int> A) {
    int low = 0, high = A.size() - 1;
    int max = A[low];
    while (low < high) {
        if (A[high] >= max)high--;
        else {
            for (int i = low; i < high; ++i) {
                if (A[i] > max)
                    max = A[i];
            }
            low = high;
            high = A.size() - 1;
        }
    }
    return low + 1;
}

int main() {
    cout << partitionDisjoint({5, 0, 3, 8, 6});
    cout << partitionDisjoint({1, 1, 1, 0, 6, 12});
    cout << partitionDisjoint({32, 57, 24, 19, 0, 24, 49, 67, 87, 87});
}