#include "alg.h"

int n = 0;
int m = 0;

void dfs(vector<vector<char>> &board, int row, int col, vector<vector<char>> &visited) {
    if (board[row][col] == 'X' || visited[row][col] == '1') return;
    visited[row][col] = '1';
    if (row > 0) dfs(board, row - 1, col, visited);
    if (row < n - 1) dfs(board, row + 1, col, visited);
    if (col > 0) dfs(board, row, col - 1, visited);
    if (col < m - 1) dfs(board, row, col + 1, visited);
}


void solve(vector<vector<char>> &board) {
    n = board.size();
    if (n == 0) return;
    m = board[0].size();
    if (m == 0) return;

    vector<vector<char>> visited(n, vector<char>(m, '0'));

    for (int i = 0; i < n; i++) {
        if (board[i][0] == 'O') dfs(board, i, 0, visited);
        if (board[i][m - 1] == 'O') dfs(board, i, m - 1, visited);
    }

    for (int i = 0; i < m; i++) {
        if (board[0][i] == 'O') dfs(board, 0, i, visited);
        if (board[n - 1][i] == 'O') dfs(board, n - 1, i, visited);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 'O' && visited[i][j] == '0') board[i][j] = 'X';
        }
    }
}

int main() {

}