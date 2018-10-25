#include "alg.h"

int maxArea(vector<int> &height) {
    int max = 0;
    for (int low = 0, high = height.size() - 1; low < high;) {
        int area = (height[low] < height[high] ? height[low] : height[high]) * (high - low);
        max = area > max ? area : max;
        if (height[low] < height[high]) low++;
        else high--;
    }
    return max;
}

int main() {
    vector<int> v = {1,8};
    cout << maxArea(v);
}