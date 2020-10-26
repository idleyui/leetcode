#include "alg.h"

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
    int p1 = m - 1, p2 = n - 1, p = m + n - 1;
    while (p >= 0) {
        if (p1 < 0) nums1[p--] = nums2[p2--];
        else if (p2 < 0) nums1[p--] = nums1[p1--];
        else if (nums1[p1] > nums2[p2]) {
            nums1[p--] = nums1[p1--];
        } else {
            nums1[p--] = nums2[p2--];
        }
    }
}

void merge_2(vector<int> &nums1, int m, vector<int> &nums2, int n) {
    int i = m - 1, j = n - 1, k = m + n - 1;
    while (i >= 0 && j >= 0) {
        if (nums1[i] >= nums2[j]) nums1[k--] = nums1[i--];
        else nums1[k--] = nums2[j--];
    }
    while (j >= 0) nums1[k--] = nums2[j--];
}

int main() {

}