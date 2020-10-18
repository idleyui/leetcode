// https://www.acwing.com/problem/content/829/
#include<iostream>

using namespace std;

const int N = 100010;

int M;
int A[N], L[N], R[N];
int idx;

void init() {
    R[0] = 1, L[1] = 0;
    idx = 2;
}

// insert right
void insert(int k, int x) {
    L[idx] = k;
    R[idx] = R[k];
    R[k] = idx;
    L[R[idx]] = idx;
    A[idx++] = x;
}

void del(int k) {
    R[L[k]] = R[k];
    L[R[k]] = L[k];
}


int main() {
    cin >> M;
    char op;
    int k, x;
    init();
    while(M--) {
        cin >> op;
        if (op == 'L') {
            cin >> x;
            insert(0, x);
        } else if (op == 'R') {
            cin >> x;
            insert(L[1], x);
        } else if (op == 'D') {
            cin >> k;
            del(k+1);
        } else if (op == 'I') {
            cin >> op;
            cin >> k >> x;
            if (op == 'L') insert(L[k+1], x);
            else insert(k+1, x);
        }
    }

    int h = R[0];
    while(h != 1) {
        cout << A[h] << ' ';
        h = R[h];
    }
}
