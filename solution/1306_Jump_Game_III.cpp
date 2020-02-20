#include "alg.h"

// Solution 1: DFS
bool dfs(vector<int> &arr, int start, vector<bool> visited) {
    if (start < 0 || start >= arr.size() || visited[start]) return false;
    int step = arr[start];
    visited[start] = true;
    return step == 0 || dfs(arr, start - step, visited) || dfs(arr, start + step, visited);
}

bool canReach1(vector<int> &arr, int start) {
    return dfs(arr, start, vector<bool>(arr.size(), false));
}

// change arr to avoid visited array
// https://leetcode.com/problems/jump-game-iii/discuss/473221/Simple-Java-DFS-solution
bool canReach1_(vector<int> &arr, int start) {
    if (start < 0 || start >= arr.size() || arr[start] < 0) return false;
    if (arr[start] == 0) return true;
    arr[start] = -arr[start];
    return canReach1_(arr, start - arr[start]) || canReach1_(arr, start + arr[start]);
}

// Solution 2: BFS
bool canReach2(vector<int> &arr, int start) {
    deque<int> tovisit = {0};
    vector<bool> visited(arr.size(), false);
    while (!tovisit.empty()) {
        int i = tovisit.front();
        tovisit.pop_front();
        if (i < 0 || i >= arr.size() || visited[i]) continue;
        if (arr[i] == 0) return true;
        visited[i] = true;
        tovisit.push_back(i + arr[i]);
        tovisit.push_back(i - arr[i]);
    }
    return false;
}

int main() {

}