// https://www.acwing.com/problem/content/796/
#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

vector<int> divide(vector<int> &A, int b) {
    vector<int> ans;
    int carry = 0;
    for (int i = A.size() - 1; i >= 0; i--) {

        carry = carry * 10 + A[i];
        ans.push_back(carry / b);
        carry = carry % b;
    }
    reverse(ans.begin(), ans.end());

    while (ans.size() > 1 && ans.back() == 0) ans.pop_back();

    ans.push_back(carry);
    return ans;
}

int main() {

    string a;
    int b;
    cin >> a >> b;
    vector<int> A;
    for (int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');

    vector<int> ans = divide(A, b);

    for (int i = ans.size() - 2; i >= 0; i--) cout << ans[i];
    cout << endl << ans.back();
}
