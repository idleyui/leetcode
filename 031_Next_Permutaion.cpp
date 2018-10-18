#include "alg.h"

// find the most right one that has greater in the right
void nextPermutaion(vector<int> &nums) {
    if (nums.size() < 2)return;
    auto max = nums.end() - 1, item = nums.end() - 2;
    for (; item != nums.begin() && *item >= *max; --item);
    if (item == nums.begin() && *item >= *max) {
        sort(item, nums.end());
    } else {
        sort(item + 1, nums.end(), greater<int>());
        swap(*item, *(item + 1));
    }
}

int main() {
    auto vv = mkvv({
                           {1, 2, 3},
                           {3, 2, 1},
                           {1, 1, 5},
                           {1, 3, 2}
                   });
    for (auto v: vv) {
        nextPermutaion(v);
        print_container(v);
    }
}
