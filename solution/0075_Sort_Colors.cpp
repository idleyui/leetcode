#include "alg.h"

// Solution 1: counting sort
void sortColors_1(vector<int> &nums) {
    int zero = 0, one = 0, two = 0;
    for (int i: nums) {
        if (i == 0) zero++;
        else if (i == 1) one++;
        else if (i == 2) two++;
    }

    for (int i = 0; i < nums.size(); i++) {
        if (i < zero) nums[i] = 0;
        else if (i < zero + one) nums[i] = 1;
        else nums[i] = 2;
    }
}


// Solution 2: Two-Pointer
// https://leetcode.com/problems/sort-colors/discuss/26500/Four-different-solutions
void sortColors_2(vector<int> &nums) {
//    [zero, two] not sort
    int zero = 0, two = nums.size() - 1;
    for (int i = 0; i <= two; i++) {
        if (nums[i] == 0) swap(nums[zero++], nums[i]);
        if (nums[i] == 2) swap(nums[two--], nums[i--]);
    }
}

//https://leetcode.com/problems/sort-colors/discuss/26500/Four-different-solutions
void sortColors_3(int A[], int n) {
    int n0 = -1, n1 = -1, n2 = -1;
    for (int i = 0; i < n; ++i) {
        if (A[i] == 0) {
            A[++n2] = 2;
            A[++n1] = 1;
            A[++n0] = 0;
        } else if (A[i] == 1) {
            A[++n2] = 2;
            A[++n1] = 1;
        } else if (A[i] == 2) {
            A[++n2] = 2;
        }
    }
}

int main() {
    vector<vector<int>> tests = {
            {2, 0, 2, 1, 1, 0},
            {2, 1, 2, 1, 1, 1},
            {0, 1, 1, 1, 1, 1},
            {1, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0},
            {1, 1, 1, 1, 1},
            {2, 2, 2, 2, 2}
    };
    for (auto &nums: tests) {
        sortColors_1(nums);
        print_container(nums);
    }
}