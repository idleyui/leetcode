#include "alg.h"


vector<int> findDisappearedNumbers(vector<int> &nums) {
    for (int i = 0; i < nums.size();) {
        if (nums[i] <= 0) {
            i++;
            continue;
        }
        int dist = nums[i] - 1;
        if (dist == i) {
            i++;
        } else if (nums[dist] == nums[i]) {
            nums[dist] = -2;
            nums[i] = 0;
            i++;
        } else if (nums[dist] == 0) {
            nums[dist] = nums[i];
            nums[i] = 0;
            i++;
        } else {
            swap(nums[dist], nums[i]);
        }
    }
    vector<int> result = {};
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << ",";
        if (nums[i] == 0) result.push_back(i + 1);
    }
    return result;
}

vector<int> simple(vector<int> &nums) {
    for (int i = 0; i < nums.size(); i++) {
        int dist = abs(nums[i]) - 1;
        if (nums[dist] > 0) {
            nums[dist] = -nums[dist];
        }
    }
    vector<int> result = {};
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] > 0) {
            result.push_back(i + 1);
        }
    }
    return result;
}

int main() {

}