#include "alg.h"

vector<bool> finish;
vector<vector<int>> pre_list;
vector<bool> visited;
vector<int> order;

bool dfs(int id) {
    if (finish[id])return true;
    visited[id] = true;
    for (int pre_id: pre_list[id]) {
        if (visited[pre_id])return false;
        if (!dfs(pre_id))return false;
    }
    visited[id] = false;
    finish[id] = true;
    order.push_back(id);
    return true;
}


vector<int> findOrder(int numCourses, vector<pair<int, int>> prerequisites) {
    pre_list = vector<vector<int>>(numCourses, vector<int>());
    for (auto p: prerequisites) {
        pre_list[p.first].push_back(p.second);
    }

    finish = vector<bool>(numCourses, false);
    visited = vector<bool>(numCourses, false);
    order.clear();


    while (order.size() < numCourses) {
        for (int j = 0; j < numCourses; ++j) { visited[j] = false; }
        int i = 0;
        for (; i < numCourses && finish[i]; i++);
        if (!dfs(i))return {};
    }
    return order;
}


int main() {
    print_container(findOrder(2, {{1, 0}}));
    print_container(findOrder(2, {{1, 0}, {0, 1}}));
    print_container(findOrder(4, {{3, 1}, {0, 1}, {1, 3}, {3, 2}}));
    print_container(findOrder(4, {{1, 0}, {2, 0}, {3, 1}, {3, 2}}));
}
