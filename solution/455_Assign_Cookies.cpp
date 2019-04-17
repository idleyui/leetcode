#include "alg.h"

int findContentChildren(vector<int> &g, vector<int> &s) {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int cnt = 0;
    for (int i = 0, j = 0; j < s.size() && i < g.size();) {
        if (g[i] <= s[j]) {
            cnt++;
            i++;
            j++;
        } else {
            j++;
        }
    }
    return cnt;
}
