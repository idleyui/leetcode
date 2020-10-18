// https://www.acwing.com/problem/content/846/
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

const int N = 100, M = 100;
vector<vector<int>> Maze(N, vector<int>(M, 0));
vector<vector<int>> Dist(N, vector<int>(M, -1));
queue<pair<int, int>> q;
int n, m;

void check(int x1, int y1, int x2, int y2) {
    if (x2 >= 0 && x2 < n && y2 >= 0 && y2 < m && Maze[x2][y2] == 0 && Dist[x2][y2] == -1) {
        Dist[x2][y2] = Dist[x1][y1] + 1;
        q.push({x2, y2});
    }
}

int bfs() {
    Dist[0][0] = 0;
    q.push({0, 0});
    while (!q.empty()) {
        auto front = q.front();
        q.pop();
        int x = front.first, y = front.second;
        check(x, y, x - 1, y);
        check(x, y, x + 1, y);
        check(x, y, x, y - 1);
        check(x, y, x, y + 1);
    }
    return Dist[n - 1][m - 1];
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> Maze[i][j];
        }
    }

    cout << bfs();
}

