#include "alg.h"

unordered_map<char, int> label2id;

int dfs(unordered_map<int, unordered_set<int>> &parent2child, int id, string &labels, int target,
        vector<vector<int>> &dp, vector<int> &visited) {
    if (dp[id][target] >= 0) return dp[id][target];
    int sum = 0;
    visited[id] = 1;
    bool eql = label2id[labels[id]] == target;
    int my_sum = 0;
    int my_target = label2id[labels[id]];
    for (int child: parent2child[id]) {
        if (visited[child]) continue;
        sum += dfs(parent2child, child, labels, target, dp, visited);
        if (!eql) my_sum += dfs(parent2child, child, labels, my_target, dp, visited);
    }
    visited[id] = 0;
    if (!eql) {
        dp[id][my_target] = my_sum + 1;
    }
    dp[id][target] = sum + (eql ? 1 : 0);
    return dp[id][target];
}

vector<int> countSubTrees(int n, vector<vector<int>> &edges, string labels) {
    int id = 0;
    for (char c: labels) { if (!label2id.count(c)) label2id[c] = id++; }
    vector<vector<int>> dp(n, vector<int>(id, -1));
    vector<int> visited(n, 0);

    unordered_map<int, unordered_set<int>> parent2child;
    for (auto &v: edges) {
        parent2child[v[0]].insert(v[1]);
        parent2child[v[1]].insert(v[0]);
    }

    dfs(parent2child, 0, labels, label2id[labels[0]], dp, visited);

    vector<int> result;
    result.reserve(n + 10);
    for (int i = 0; i < n; i++) {
        result.push_back(dp[i][label2id[labels[i]]]);
    }
    return result;
}

int main() {
    vector<vector<int>> edges = {{0, 1},
                                 {0, 2},
                                 {1, 4},
                                 {1, 5},
                                 {2, 3},
                                 {2, 6}};
    int n = 7;
    string labels = "abaedcd";
    print_container(countSubTrees(n, edges, labels));
}