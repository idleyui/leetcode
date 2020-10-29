#include "alg.h"

void dfs(vector<vector<int>> &res, vector<int> &tmp, int n, int i, int k) {
    if (k == 0) {
        if (0 == n) res.push_back(tmp);
        return;
    }
    if (k > 9 - i + 1) return;
    if (n < 0) return;
    dfs(res, tmp, n, i + 1, k);
    tmp.push_back(i);
    dfs(res, tmp, n - i, i + 1, k - 1);
    tmp.pop_back();
}

vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> res;
    vector<int> tmp;
    dfs(res, tmp, n, 1, k);
    return res;
}

int main() {
    auto res = combinationSum3(9, 45);
    cout << res.size();
}