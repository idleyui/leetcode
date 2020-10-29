#include "alg.h"

void dfs(vector<vector<int>> &res, vector<int> &tmp, int n, int i, int k) {
    if (k == 0) {
        res.push_back(tmp);
        return;
    }
    if (k > n - i + 1) return;
    dfs(res, tmp, n, i + 1, k);
    tmp.push_back(i);
    dfs(res, tmp, n, i + 1, k - 1);
    tmp.pop_back();
}

vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> res;
    vector<int> tmp;
    dfs(res, tmp, n, 1, k);
    return res;
}

int main() {

}