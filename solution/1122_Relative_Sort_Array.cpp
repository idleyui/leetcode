#include "alg.h"

vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2) {
    vector<int> cnt2(1001, 0);
    for (int i: arr2) cnt2[i] = 1;

    vector<int> cnt1(1001, 0);
    for (int i: arr1) cnt1[i]++;

    int pos = 0;
    for (int val: arr2) {
        for (int i = 0; i < cnt1[val]; i++) arr1[pos++] = val;
    }
    for (int i = 0; i < 1001; i++) {
        if (cnt1[i] != 0 && cnt2[i] == 0) {
            for (int k = 0; k < cnt1[i]; k++) arr1[pos++] = i;
        }
    }

    return arr1;
}

//https://leetcode.com/problems/relative-sort-array/discuss/335056/Java-in-place-solution-using-counting-sort
// use one cnt array

int main() {

}