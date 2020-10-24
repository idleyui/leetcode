// https://www.acwing.com/problem/content/869/
#include<iostream>

using namespace std;

void prime_factor(int a) {
    if (a < 2) {
        cout << a << ' ' << 1;
        return;
    };
    for (int i = 2; i <= a / i; ++i) {
        int cnt = 0;
        while (a % i == 0) {
            a /= i;
            cnt++;
        }
        if (cnt) cout << i << ' ' << cnt << endl;
    }
    if (a > 1) cout << a << ' ' << 1 << endl;
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        int a;
        cin >> a;
        prime_factor(a);
    }
}

