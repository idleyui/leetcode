// https://www.acwing.com/problem/content/870/
#include<iostream>
#include<stack>

using namespace std;

void divisor(int n) {
    stack<int> stk;
    for (int i = 1; i <= n / i; i++) {
        if (n % i == 0) {
            cout << i << ' ';
            stk.push(n / i);
        }
    }
    if (n / stk.top() == stk.top()) stk.pop();
    while (!stk.empty()) {
        cout << stk.top() << ' ';
        stk.pop();
    }
    cout << endl;
}


int main() {
    int n;
    cin >> n;
    while (n--) {
        int a;
        cin >> a;
        divisor(a);
    }
}

