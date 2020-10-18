// https://www.acwing.com/problem/content/795/
#include<vector>
#include<iostream>

using namespace std;

vector<int> multi(vector<int> &A, int b) {
    vector<int> ans;
    int carry = 0;
    for (int i = 0; i < A.size() || carry; i++) {
        if (i < A.size()) carry = A[i] * b + carry;
        ans.push_back(carry % 10);
        carry /= 10;
    }

    while(ans.size() > 1 && ans.back() == 0)    ans.pop_back();

    return ans;
}

int main() {
    string a;
    int b;
    cin >> a >> b;
    vector<int> A;
    for (int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');

    vector<int> ans = multi(A, b);

    for (int i = ans.size() - 1; i >= 0; i--) cout << ans[i];
}
