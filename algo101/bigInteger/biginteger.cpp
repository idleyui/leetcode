#include "alg.h"

vector<int> add(vector<int> &A, vector<int> &B) {
    vector<int> ans;
    int carry = 0;
    for (int i = 0; i < A.size() || i < B.size() || carry; i++) {
        if (i < A.size()) carry += A[i];
        if (i < B.size()) carry += B[i];
        ans.push_back(carry % 10);
        carry = carry / 10;
    }
    return ans;
}


vector<int> add_1(vector<int> &A, vector<int> &B) {
    if (A.size() < B.size()) return add_1(B, A);
    vector<int> ans;
    int carry = 0;
    for (int i = 0; i < A.size(); i++) {
        carry += A[i];
        if (i < B.size()) carry += B[i];
        ans.push_back(carry % 10);
        carry = carry / 10;
    }
    if (carry) ans.push_back(carry);
    return ans;
}

// A >= B >= 0
vector<int> _minus(vector<int> &A, vector<int> &B) {
    vector<int> ans;
    int borrow = 0;
    for (int i = 0; i < A.size(); i++) {
        int diff = A[i] - B[i] - borrow;
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        }
        ans.push_back(diff);
    }
    return ans;
}

// check A >= B
bool cmp(vector<int> &A, vector<int> &B) {
    if (A.size() > B.size()) return true;
    for (int i = A.size() - 1; i >= 0; i--) {
        if (A[i] != B[i]) return A[i] > B[i];
    }
    return true;
}

int main() {
    string a = "123456", b = "234567";
    vector<int> A, B;
    for (int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');
    for (int i = b.size() - 1; i >= 0; i--) B.push_back(b[i] - '0');
    auto sum = add(A, B);
    for (int i = sum.size() - 1; i >= 0; i--) cout << sum[i];
    cout << endl;
    auto diff = _minus(B, A);
    for (int i = diff.size() - 1; i >= 0; i--) cout << diff[i];
}