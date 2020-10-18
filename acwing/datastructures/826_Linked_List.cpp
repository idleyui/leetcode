//// https://www.acwing.com/problem/content/828/
#include<iostream>

using namespace std;

const int N = 100010;
int M, idx, head;
int A[N], Next[N];

void init() {
    head = -1;
    idx = 0;
}

void insert_head(int val) {
    Next[idx] = head;
    head = idx;
    A[idx++] = val;
}

void insert(int k, int val) {
    Next[idx] = Next[k];
    Next[k] = idx;
    A[idx++] = val;
}

void del(int k) {
    if (k < 0) head = Next[head];
    else Next[k] = Next[Next[k]];
}

int main() {
    cin >> M;
    char op;
    int k, x;
    init();
    while(M--) {
        cin >> op;
        if (op == 'H') {
            cin >> x;
            insert_head(x);
        } else if (op == 'D') {
            cin >> k;
            del(k-1);
        } else {
            cin >> k >> x;
            insert(k-1, x);
        }
    }

    while(head >= 0) {
        cout << A[head] << ' ';
        head = Next[head];
    }
}

