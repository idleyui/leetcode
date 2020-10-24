// https://www.acwing.com/problem/content/844/
#include<iostream>

using namespace std;


bool is_prime(int a) {
    if (a < 2) return false;
    // i*i might overflow
    for (int i = 2; i <= a / i; ++i) {
        if (a % i == 0) return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        int a;
        cin >> a;
        if (is_prime(a)) cout << "Yes";
        else cout << "No";
        cout << endl;
    }
}

