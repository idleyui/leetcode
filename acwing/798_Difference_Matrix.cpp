// https://www.acwing.com/problem/content/800/
#include <iostream>

using namespace std;

const int N = 1010;
int n, m, q;
int A[N][N], B[N][N];

void insert(int x1, int y1, int x2, int y2, int c) {
    B[x1][y1] += c;
    B[x1][y2+1] -= c;
    B[x2+1][y1] -= c;
    B[x2+1][y2+1] += c;
}

int main() {
    cin >> n >> m >> q;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> A[i][j];
            insert(i, j, i, j, A[i][j]);
        }
    }

    int x1, y1, x2, y2, c;
    while(q--) {
        cin >> x1 >> y1 >> x2 >> y2 >> c;
        insert(x1, y1, x2, y2, c);
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            B[i][j] = B[i][j] + B[i-1][j] + B[i][j-1] - B[i-1][j-1];
            cout << B[i][j] << ' ';
        }
        cout << endl;
    }
}
