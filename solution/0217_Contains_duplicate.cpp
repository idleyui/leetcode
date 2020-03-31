#include "alg.h"


bool containsDuplicate_1(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] == nums[i - 1]) return true;
    }
    return false;
}


bool containsDuplicate_2(vector<int> &nums) {
    unordered_set<int> cnt;
    for (int i: nums) {
        if (cnt.count(i)) return true;
        cnt.insert(i);
    }
    return false;
}


int main() {

}