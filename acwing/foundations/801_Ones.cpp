// https://www.acwing.com/problem/content/803/
#include <vector>
#include <iostream>

using namespace std;

int cntOnes(int n) {
    int cnt;
    while (n) {
        cnt++;
        n = n - (n & -n);
    }
    return cnt;
}

int main() {
    int n, num;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> num;
        cout << cntOnes(num) << ' ';
    }
}

