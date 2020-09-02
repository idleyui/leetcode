#include "alg.h"

int digitSum(int n) {
    int sum = 0;
    while (n) {
        sum += (n % 10);
        n /= 10;
    }
    return sum;
}

int movingCount(vector<vector<int>> &visited, int n, int m, int i, int j, int k) {
    if (i < 0 || i >= n || j < 0 || j >= m || visited[i][j]) return 0;
    int sum = digitSum(i) + digitSum(j);
    if (sum > k) return 0;
    visited[i][j] = 1;
    int subSum = movingCount(visited, n, m, i + 1, j, k)
                 + movingCount(visited, n, m, i - 1, j, k)
                 + movingCount(visited, n, m, i, j + 1, k)
                 + movingCount(visited, n, m, i, j - 1, k);
    return subSum + 1;
}

int movingCount(int n, int m, int k) {
    vector<vector<int>> visited(n, vector<int>(m, 0));
    return movingCount(visited, n, m, 0, 0, k);
}


int main() {

}