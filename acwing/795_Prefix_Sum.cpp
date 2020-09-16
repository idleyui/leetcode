// https://www.acwing.com/problem/content/797/
#include <vector>
#include <iostream>

using namespace std;

vector<int> build_prefix_sum(vector<int> &A) {
    vector<int> prefix_sum(A.size() + 1, 0);
    for (int i = 0; i < A.size(); i++) prefix_sum[i + 1] = prefix_sum[i] + A[i];
    return prefix_sum;
}

int main() {
    ios::sync_with_stdio(false); //accelerate
    int n, m;
    cin >> n >> m;
    vector<int> A(n, 0);
    for (int i = 0; i < n; i++) cin >> A[i];
    auto prefix_sum = build_prefix_sum(A);

    int l, r;
    for (int i = 0; i < m; i++) {
        cin >> l >> r;
        cout << prefix_sum[r] - prefix_sum[l - 1] << endl;
    }
}