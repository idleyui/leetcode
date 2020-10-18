// https://www.acwing.com/problem/content/798/
#include<iostream>

using namespace std;

const int N = 1010;
int n, m, q;
int A[N][N], S[N][N];

int main() {
    cin >> n >> m >> q;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> A[i][j];
            S[i][j] = S[i][j-1] + S[i-1][j] - S[i-1][j-1] + A[i][j];
        }
    }

    int x1, y1, x2, y2;
    while(q--) {
        cin >> x1 >> y1 >> x2 >> y2;
        cout << S[x2][y2] - S[x1-1][y2] - S[x2][y1-1] + S[x1-1][y1-1] << endl;
    }

}
