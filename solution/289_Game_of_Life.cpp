#include "alg.h"

int cnt_one(vector <vector<int>> &board, int i, int j, int n, int m) {
    if (i < 0 || i >= n || j < 0 || j >= m) return 0;
    if (board[i][j] >= 0) {
        return board[i][j];
    } else if (board[i][j] > -10) {
        return 0;
    } else {
        return 1;
    }
}

int cnt(vector <vector<int>> &board, int i, int j, int n, int m) {
    int rt = 0;
    for (int i1 = i - 1; i1 <= i + 1; i1++) {
        for (int j1 = j - 1; j1 <= j + 1; j1++) {
            rt += cnt_one(board, i1, j1, n, m);
        }
    }
    return board[i][j] == 1 ? rt - 1 : rt;
}

void gameOfLife(vector <vector<int>> &board) {
//         0->-N 1s
//         1->-1N
    int n = board.size(), m = n > 0 ? board[0].size() : 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int neighber = cnt(board, i, j, n, m);
            // cout << neighber << ',';
            if (board[i][j] == 0) {
                board[i][j] = -neighber;
            } else {
                board[i][j] = -10 - neighber;
            }
            // cout << board[i][j] << endl;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] > -10) {
                board[i][j] = board[i][j] == -3 ? 1 : 0;
            } else if (board[i][j] > -12 || board[i][j] < -13) {
                board[i][j] = 0;
            } else {
                board[i][j] = 1;
            }
        }
    }
}

int main() {

}