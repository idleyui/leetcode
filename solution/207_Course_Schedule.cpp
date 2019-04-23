#include "alg.h"

vector<bool> finish;
vector<vector<int>> pre_list;
set<int> visited;
int cnt = 0;

bool canFinish(int id) {
    if (finish[id])return true;
    set<int> tmp_v;
    for (int pre_id: pre_list[id]) {
        if (visited.count(pre_id))return false;
        if (!canFinish(pre_id))return false;
        tmp_v.insert(pre_id);
    }
    visited.insert(tmp_v.begin(), tmp_v.end());
    cnt++;
    finish[id] = true;
    return true;
}

bool canFinish(int numCourses, vector<pair<int, int>> prerequisites) {
    pre_list = vector<vector<int>>(numCourses, vector<int>());
    for (auto p: prerequisites) {
        pre_list[p.first].push_back(p.second);
    }

    finish = vector<bool>(numCourses, false);

    while (cnt < numCourses) {
        visited.clear();
        int i = 0;
        for (; i < numCourses && finish[i]; i++);
        visited.insert(i);
        bool b = canFinish(i);
        if (!b)return false;
    }
    return true;


//    deque<int> to_check;
//    int not_visited = numCourses;
//    while (not_visited) {
//        if (to_check.empty()) {
//            int i = 0;
//            for (; i < visited.size() && visited[i]; i++);
//            to_check.push_back(i);
//            visited[i] = true;
//            not_visited--;
//        }
//
//        set<int> new_visit;
//        int n = to_check.size();
//        for (int i = 0; i < n; i++) {
//            vector<int> pre_list = pre[to_check.front()];
//            for (auto pre_id: pre_list) {
//                if (visited[pre_id]) {
//                    return false;
//                }
//                to_check.push_back(pre_id);
////                visited[pre_id] = true;
//                new_visit.insert(pre_id);
//                not_visited--;
//            }
//            to_check.pop_front();
//        }
//        for (int i: new_visit)visited[i] = true;
//        not_visited -= new_visit.size();
//    }
//    return true;

}

int main() {
//    cout << canFinish(2, {{1, 0}});
//    cout << canFinish(2, {{1, 0}, {0, 1}});
    cout << canFinish(4, {{3, 1},
                          {0, 1},
                          {1, 3},
                          {3, 2}});
}