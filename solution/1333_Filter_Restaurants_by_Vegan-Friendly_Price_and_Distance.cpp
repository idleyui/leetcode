#include "alg.h"

static bool cmp(vector<int> &r1, vector<int> &r2) {
    return r1[1] > r2[1] || (r1[1] == r2[1] && r1[0] > r2[0]);
}

vector<int> filterRestaurants(vector<vector<int>> &restaurants, int veganFriendly, int maxPrice, int maxDistance) {
    int l = 0, h = restaurants.size() - 1;
    while (l <= h) {
        auto r = restaurants[l];
        if ((veganFriendly && r[2] == 0) ||
            r[3] > maxPrice ||
            r[4] > maxDistance) {
            swap(restaurants[l], restaurants[h]);
            h--;
        } else {
            l++;
        }
    }
    sort(restaurants.begin(), restaurants.begin() + l, cmp);

    vector<int> ans(l, 0);
    for (int i = 0; i < l; i++) {
        ans[i] = restaurants[i][0];
    }
    return ans;
}

int main() {

}

3
0.90 0.10 0.10
2 1 1

2
0.8 0.5
1 2
