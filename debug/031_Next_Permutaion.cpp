#include "alg.h"

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

// find the most right one that has greater in the right
void nextPermutaion(vector<int> &nums) {
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
//    int buf = *min_item;
//    while (min_item > item) {
//        *min_item = *(min_item - 1);
//        min_item--;
//    }
//    *item = buf;

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
