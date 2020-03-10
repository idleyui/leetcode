#include "alg.h"

int trap(vector<int> height) {
    int left = 0, right = height.size() - 1, max_left = 0, max_right = 0, res = 0;
    while (left <= right) {
        if (height[left] <= height[right]) {
            if (height[left] >= max_left) max_left = height[left];
            else res += max_left - height[left];
            left++;
        } else {
            if (height[right] >= max_right) max_right = height[right];
            else res += max_right - height[right];
            right--;
        }
    }
    return res;
}

int main() {
    cout << trap({0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1});
    cout << trap({1, 0, 1});
    cout << trap({});
    cout << trap({1});
}