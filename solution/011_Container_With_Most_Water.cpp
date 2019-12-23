#include "alg.h"

//https://leetcode.com/problems/container-with-most-water/discuss/6100/Simple-and-clear-proofexplanation
int maxArea(vector<int> &height) {
    int left = 0, right = height.size() - 1, max_water = -1;
    while (left < right) {
        int water = (right - left) * min(height[left], height[right]);
        max_water = max(max_water, water);
        if (height[left] < height[right]) left++;
        else right--;
    }
    return max_water;
}


int main() {
    vector<int> v = {1, 8};
    cout << maxArea(v);
}