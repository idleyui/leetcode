#include "alg.h"

vector<int> largestRectangleArea(vector<int> height) {
    vector<int> incr;
    int area = 0;
    for (int i = 0; i < height.size(); ++i) {
        while (!incr.empty() && height[*(incr.end() - 1)] > height[i]) {
            incr.pop_back();
        }
        incr.push_back(i);
    }
    return incr;
}

int main() {
    print_container(largestRectangleArea({2, 1, 5, 6, 2, 3}));
}