// https://www.acwing.com/problem/content/793/
#include<vector>
#include<iostream>

using namespace std;

vector<int> add(vector<int> &A, vector<int> &B) {
    vector<int> ans;
    int carry = 0;
    for (int i = 0, j = 0; i < A.size() || j < B.size() || carry; i++, j++) {
        if (i < A.size()) carry += A[i];
        if (j < B.size()) carry += B[j];
        ans.push_back(carry % 10);
        carry = carry / 10;
    }
    return ans;
}

int main() {
    string a, b;
    cin >> a >> b;
    vector<int> A, B;
    for (int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');
    for (int i = b.size() - 1; i >= 0; i--) B.push_back(b[i] - '0');
    auto ans = add(A, B);
    for (int i = ans.size() - 1; i >= 0; i--) cout << ans[i];
}
