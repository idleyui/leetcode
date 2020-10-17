// https://www.acwing.com/problem/content/845/
#include<iostream>
#include<vector>

using namespace std;

vector<bool> set(int n, vector<int> &A, int pos) {
    vector<bool> valid(n, true);
    for (int i = 0; i < pos; i++) {
        valid[A[i]] = false;
        int span = pos - i;
        if (A[i] + span < n) valid[A[i] + span] = false;
        if (A[i] - span >= 0) valid[A[i] - span] = false;
    }
    return valid;
}

int cnt = 0;

void print(vector<int> &A) {
    for (int i = 0; i < A.size(); ++i) {
        for (int j = 0; j < A[i]; j++) cout << '.';
        cout << 'Q';
        for (int j = A[i] + 1; j < A.size(); j++) cout << '.';
        cout << endl;
    }
    cout << endl;
}

void n_queens(int n, vector<int> &A, int pos) {
    if (pos == n) {
        print(A);
    }
    auto valid = set(n, A, pos);
    for (int i = 0; i < n; i++) {
        if (valid[i]) {
            A[pos] = i;
            n_queens(n, A, pos + 1);
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> A(n, 0);
    n_queens(n, A, 0);
}

