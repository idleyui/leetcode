// https://www.acwing.com/problem/content/831/
#include<iostream>

using namespace std;

const int N = 100010;

int q[N], head = 0, tail = 0;

int main() {
    int M;
    cin >> M;
    string op;
    int x;
    while(M--) {
        cin >> op;
        if (op == "push") {
            cin >> x;
            q[tail++] = x;
        } else if (op == "pop") {
            head++;
        } else if (op == "empty") {
            if (head == tail) cout << "YES" << endl;
            else cout << "NO" << endl;
        } else if (op == "query") {
            cout << q[head] << endl;
        }
    }
}
