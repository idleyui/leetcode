// https://www.acwing.com/problem/content/830/
#include<iostream>

using namespace std;

const int N = 100010;

int stk[N], tt = 0;

int main() {
    int M;
    cin >> M;
    string op;
    int x;
    while(M--) {
        cin >> op;
        if (op == "push") {
            cin >> x;
            stk[++tt] = x;
        } else if (op == "pop") {
            tt--;
        } else if (op == "empty") {
            if (tt == 0) cout << "YES" << endl;
            else cout << "NO" << endl;
        } else if (op == "query") {
            cout << stk[tt] << endl;
        }
    }
}
