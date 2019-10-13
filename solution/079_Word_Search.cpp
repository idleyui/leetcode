#include "alg.h"

unordered_set<string> visited = {};

string _hash(int x, int y) {
    return to_string(x) + "," + to_string(y);
}

bool find(vector<vector<char>> &board, int x, int y, string word, int pos) {
    if (pos == word.size()) return true;
    char c = word[pos];
    if (visited.count(_hash(x, y)) || x < 0 || x == board.size() || y < 0 || y == board[0].size() ||
        board[x][y] != c)
        return false;
    visited.insert(_hash(x, y));
    if (find(board, x - 1, y, word, pos + 1)) return true;
    if (find(board, x + 1, y, word, pos + 1))return true;
    if (find(board, x, y - 1, word, pos + 1))return true;
    if (find(board, x, y + 1, word, pos + 1))return true;
    visited.erase(_hash(x, y));
    return false;
}

bool exist(vector<vector<char>> &board, string word) {
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[i].size(); j++) {
//            todo empty visited
            if (board[i][j] == word[0]) {
                visited.clear();
                bool f = find(board, i, j, word, 0);
                if (f)return true;
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