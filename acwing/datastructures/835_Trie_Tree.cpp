// https://www.acwing.com/problem/content/837/
#include<iostream>

using namespace std;

const int N = 100010;

int son[N][26], cnt[N], idx;

void insert(string &s) {
    int p = 0;
    for (char c: s) {
        int u = c - 'a';
        if (!son[p][u]) son[p][u] = ++idx;
        p = son[p][u];
    }
    cnt[p]++;
}

int query(string &s) {
    int p = 0;
    for (char c: s) {
        int u = c - 'a';
        if (!son[p][u]) return 0;
        p = son[p][u];
    }
    return cnt[p];
}

int main() {
    int n;
    cin >> n;
    char op;
    string s;
    while(n--) {
        cin >> op >> s;
        if (op == 'I') {
            insert(s);
        } else if (op == 'Q') {
            cout << query(s) << endl;
        }
    }
}
