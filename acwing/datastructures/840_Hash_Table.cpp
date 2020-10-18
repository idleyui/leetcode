// https://www.acwing.com/problem/content/842/
#include<iostream>
#include<vector>

using namespace std;

const int N = 100003;
vector<vector<int>> Slot(N, vector<int>());

int pos(int x) {
    return (x % N + N) % N;
//    if (x < 0) x = -x;
//    return x % N;
}

void zipper(char op, int x) {
    if (op == 'I') {
        Slot[pos(x)].push_back(x);
    } else if (op == 'Q') {
        bool find = false;
        for (int i: Slot[pos(x)]) {
            if (i == x) {
                find = true;
                break;
            }
        }
        if (find) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}

int M = 200003;
vector<int> OpenSlot(M, 1e9 + 10);

int find(int x) {
    int p = pos(x);
    for (int i = 0; i < M; i++) {
        int val = OpenSlot[(p + i) % M];
        if (val == 1e9 + 10 || val == x) return (p + i) % M;
    }
//    int i = pos(x);
//    while (OpenSlot[i] != 1e9+10 && OpenSlot[i] != x){
//        i++;
//        if (i == M) i = 0;
//    }
//    return i;
}

void open_addr(char op, int x) {
    int p = pos(x);
    if (op == 'I') {
        int p = find(x);
        OpenSlot[p] = x;
    } else if (op == 'Q') {
        int p = find(x);
        if (OpenSlot[p] == x) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        char op;
        int x;
        cin >> op >> x;
//        zipper(op, x);
        open_addr(op, x);
    }
}

