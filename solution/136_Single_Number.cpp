#include "alg.h"

int singleNumber(vector<int> &nums) {
    int i = 0;
    for (int num: nums) {
        i ^= num;
    }
    return i;
}

int main() {
    vector<int> v = {1, 2, 3};
    cout << singleNumber(v);
}