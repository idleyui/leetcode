// https://www.acwing.com/problem/content/844/
#include<iostream>
#include<vector>

using namespace std;

int n;

void permutation(vector<int> &A, vector<bool> &visit, int i) {
    if (i == A.size()) {
        for (int num: A) cout << num << ' ';
        cout << endl;
        return;
    }

    for (int j = 1; j <= n; j++) {
        if (visit[j]) continue;
        visit[j] = true;
        A[i] = j;
        permutation(A, visit, i + 1);
        visit[j] = false;
    }
}

int main() {
    cin >> n;
    vector<int> A(n, 0);
    vector<bool> visit(n, false);
    for (int i = 0; i < n; i++) {
        A[i] = i + 1;
    }
    permutation(A, visit, 0);
}

