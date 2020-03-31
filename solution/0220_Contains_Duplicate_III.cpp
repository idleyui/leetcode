#include "alg.h"

bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t) {
}

int num(int n, int m, vector<int> score_list) {
    vector<int> cnt(m, 0);
    int color = 0, ans = INT_MAX;
    for (int r = 0, l = 0; r < n; r++) {
        cout << r << ',' << color << endl;
        int cur_color = score_list[r];
        if (cur_color == 0) {
            for (int i = 0; i < m; i++) cnt[i] = 0;
            l = r;
            color = 0;
            continue;
        }
        if (cnt[cur_color] == 0) color++;
        cnt[cur_color]++;
        if (color == m) {
            for (; l <= n && (score_list[l] == 0 || cnt[score_list[l]] > 1); l++) {
                cnt[score_list[l]]--;
            }
            ans = min(r - l + 1, ans);
            cout << r << ans << endl;
        }
    }
    return ans == INT_MAX ? -1 : ans;
}

int main() {
    cout << num(10, 5, {2, 2, 3, 1, 3, 2, 4, 1, 0, 5, 4, 3});
}