// https://www.acwing.com/problem/content/832/
#include<stack>
#include<iostream>

using namespace std;

int main() {
    int N;
    cin >> N;
    stack<int> stk;
    int i = 0;
    while(N--) {
        cin >> i;
        while(!stk.empty() && i <= stk.top()) stk.pop();
        if (stk.empty()) cout << -1 << ' ';
        else cout << stk.top() << ' ';
        stk.push(i);
    }
}
