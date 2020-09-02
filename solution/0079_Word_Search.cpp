#include "alg.h"

bool find(vector<vector<char>> &board, vector<vector<int>> &visit, string &word, int pos, int i, int j, int n, int m) {
    if (pos == word.size()) return true;
    if (i < 0 || i >= n || j < 0 || j >= m) return false;
    if (visit[i][j]) return false;
    if (word[pos] != board[i][j]) return false;
    visit[i][j] = 1;
    bool ans = find(board, visit, word, pos + 1, i + 1, j, n, m)
               || find(board, visit, word, pos + 1, i - 1, j, n, m)
               || find(board, visit, word, pos + 1, i, j + 1, n, m)
               || find(board, visit, word, pos + 1, i, j - 1, n, m);
    visit[i][j] = 0;
    return ans;
}


bool exist(vector<vector<char>> &board, string word) {
    int n = board.size(), m = board[0].size();
    vector<vector<int>> visit(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (find(board, visit, word, 0, i, j, n, m)) return true;
        }
    }
    return false;
}


bool search(vector<vector<char>> &board, string &word, int m, int n, int i, int j, int pos) {
    if (pos == word.size()) return true;
    if (i < 0 || i >= n || j < 0 || j >= m) return false;
    if (board[i][j] != word[pos]) return false;

    board[i][j] = '#';
    bool ans = search(board, word, m, n, i + 1, j, pos + 1) ||
               search(board, word, m, n, i - 1, j, pos + 1) ||
               search(board, word, m, n, i, j + 1, pos + 1) ||
               search(board, word, m, n, i, j - 1, pos + 1);
    board[i][j] = word[pos];
    return ans;
}

bool exist(vector<vector<char>> &board, string word) {
    int n = board.size(), m = board[0].size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (search(board, word, m, n, i, j, 0)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    vector<vector<char>> board = {
            {'A', 'B', 'C', 'E'},
            {'S', 'F', 'C', 'S'},
            {'A', 'D', 'E', 'E'}
    };
    vector<string> words = {"SEE", "ABCCED", "ABCB"};
    for (auto word: words)
        cout << exist(board, word);
}