#include "alg.h"

vector<int> constructRectangle(int area) {
    int W = 1;
    for (int w = 1; w < area && area / w >= w; w++) {
        if (area % w == 0) W = w;
    }
    return {area / W, W};
}

// https://leetcode.com/problems/construct-the-rectangle/discuss/97210/3-line-Clean-and-easy-understand-solution
vector<int> constructRectangle_2(int area) {
    int a = sqrt(area);
    while (area % a) a--;
    return {area / a, a};
}

int main() {

}