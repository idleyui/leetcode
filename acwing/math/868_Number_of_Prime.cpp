// https://www.acwing.com/problem/content/870/
#include<iostream>

using namespace std;

const int N = 1000010;
int P[N], st[N];

int primes(int n) {
    int cnt = 0;
    for (int i = 2; i <= n; i++) {
        if (!st[i]) {
            for (int j = i + i; j <= n; j += i) st[j] = 1;
            cnt++;
        }
    }
    return cnt;
}

int main() {
    int n;
    cin >> n;
    cout << primes(n);
}

