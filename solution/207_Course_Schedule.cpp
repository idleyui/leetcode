#include "alg.h"

vector<bool> finish;
vector<vector<int>> pre_list;
vector<bool> visited;
int order = 0;

bool dfs(int id) {
    if (finish[id])return true;
    visited[id] = true;
    for (int pre_id: pre_list[id]) {
        if (visited[pre_id])return false;
        if (!dfs(pre_id))return false;
    }
    visited[id] = false;
    order++;
    finish[id] = true;
    return true;
}

bool findOrder(int numCourses, vector<pair<int, int>> prerequisites) {
    pre_list = vector<vector<int>>(numCourses, vector<int>());
    for (auto p: prerequisites) {
        pre_list[p.first].push_back(p.second);
    }

    finish = vector<bool>(numCourses, false);
    visited = vector<bool>(numCourses, false);


    while (order < numCourses) {
        for (int j = 0; j < numCourses; ++j) { visited[j] = false; }
        int i = 0;
        for (; i < numCourses && finish[i]; i++);
        if (!dfs(i))return false;
    }
    return true;
}


int main() {
//    cout << dfs(2, {{1, 0}});
    cout << findOrder(2, {{1, 0},
                          {0, 1}});
    cout << findOrder(4, {{3, 1},
                          {0, 1},
                          {1, 3},
                          {3, 2}});
}