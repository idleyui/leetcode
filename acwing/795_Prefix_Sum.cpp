// https://www.acwing.com/problem/content/797/
#include<iostream>

using namespace std;

const int N = 100010;

int n, m, l, r;
int A[N], S[N];

int main() {
    ios::sync_with_stdio(false); //accelerate
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> A[i];
        S[i] = S[i-1] + A[i];
    }

    while(m--) {
        cin >> l >> r;
        cout << S[r] - S[l-1] << endl;
    }
}
