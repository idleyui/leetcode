//// https://www.acwing.com/problem/content/828/
#include<vector>
#include<iostream>

using namespace std;

int head_i, idx;

void init() {
    head_i = -1;
    idx = 0;
}

void head(vector<int> &num, vector<int> &next, int x) {
    num[idx] = x;
    next[idx] = head_i;
    head_i = idx;
    idx++;
}

void insert(vector<int> &num, vector<int> &next, int k, int x) {
    num[idx] = x;
    next[idx] = next[k];
    next[k] = idx;
    idx++;
}

void del(vector<int> &num, vector<int> &next, int k) {
    if (k < 0) head_i = next[head_i];
    else next[k] = next[next[k]];
}

void traversal(vector<int> &num, vector<int> &next) {
    int p = head_i;
    while (p >= 0) {
        cout << num[p] << ' ';
        p = next[p];
    }
}

int main() {
    vector<int> num(100010, 0);
    vector<int> next(100010, 0);
    int M, k, x;
    char op;
    cin >> M;
    init();
    while (M--) {
        cin >> op;
        if (op == 'H') {
            cin >> x;
            head(num, next, x);
        } else if (op == 'D') {
            cin >> k;
            del(num, next, k - 1);
        } else if (op == 'I') {
            cin >> k >> x;
            insert(num, next, k - 1, x);
        }
    }
    traversal(num, next);
}
