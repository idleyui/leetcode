#include "alg.h"


// find the most right one that has greater in the right
// optim sort by reverse
// https://leetcode.com/problems/next-permutation/discuss/13867/C%2B%2B-from-Wikipedia
void nextPermutation(vector<int> &nums) {
    int i = nums.size() - 2;
    for (; i >= 0 && nums[i] >= nums[i + 1]; i--);
    if (i < 0) {
        reverse(nums.begin(), nums.end());
    } else {
        int j = nums.size() - 1;
        for (; nums[j] <= nums[i]; j--);
        swap(nums[i], nums[j]);
        reverse(nums.begin() + i + 1, nums.end());
    }
}

// naive idea, sort is not necessary
vector<int>::iterator min_greater(vector<int>::iterator l, vector<int>::iterator r, int base) {
    auto min_item = l;
    for (; min_item != r && *min_item <= base; min_item++);

    for (auto item = min_item; item != r; item++) {
        if (*item > base && *min_item > *item) {
            min_item = item;
        }
    }

    return min_item;
}

void nextPermutation(vector<int> &nums) {
    if (nums.size() < 2)return;
    auto max = nums.end() - 1, item = nums.end() - 2;
    for (; item >= nums.begin() && *item >= *max; --item)
        max = item;

    if (item == nums.begin() - 1) {
        sort(nums.begin(), nums.end());
        return;
    }

    //    find min item
    auto min_item = min_greater(item + 1, nums.end(), *item);
    swap(*item, *min_item);
    sort(item + 1, nums.end());
}

int main() {
    auto vv = mkvv({
                           {1, 2, 3},
                           {1, 3, 2},
                           {3, 2, 1},
                           {1, 1, 5},
                           {1, 3, 2},
                           {2, 3, 1}
                   });
    for (auto v: vv) {
        nextPermutaion(v);
        print_container(v);
    }
}
