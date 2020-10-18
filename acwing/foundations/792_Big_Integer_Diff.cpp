// https://www.acwing.com/problem/content/794/
// !note
// handle negative result carefully
// cmp function
// (diff+10)%10 trick
#include<vector>
#include<iostream>

using namespace std;

// A >= B >= 0
vector<int> _minus(vector<int> &A, vector<int> &B) {
    vector<int> ans;
    int borrow = 0;
    for (int i = 0; i < A.size(); i++) {
        int diff = A[i] - borrow;
        if (i < B.size()) diff -= B[i];
        // trick!
        ans.push_back((diff + 10) % 10);
        borrow = diff < 0 ? 1 : 0;
    }

    while(ans.size() > 1 && ans.back() == 0)    ans.pop_back();

    return ans;
}

// check A >= B
bool cmp(vector<int> &A, vector<int> &B) {
    if (A.size() != B.size()) return A.size() > B.size();
    for (int i = A.size() - 1; i >= 0; i--) {
        if (A[i] != B[i]) return A[i] > B[i];
    }
    return true;
}

int main() {
    string a, b;
    cin >> a >> b;
    vector<int> A, B;
    for (int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');
    for (int i = b.size() - 1; i >= 0; i--) B.push_back(b[i] - '0');

    vector<int> ans;
    if (cmp(A, B)) {
        ans = _minus(A, B);
    } else {
        cout << '-';
        ans = _minus(B, A);
    }

    for (int i = ans.size() - 1; i >= 0; i--) cout << ans[i];
}
