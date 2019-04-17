#include "alg.h"

bool comp(const pair<int, int> &a, const pair<int, int> &b) {
    return a.first < b.first || (a.first == b.first && a.second < b.second);
}

// think in boundary value
// for this question: what the position of the shortest person?
vector<pair<int, int>> reconstructQueue(vector<pair<int, int>> &people) {
    vector<pair<int, int>> result(people.size(), {-1, -1});
    sort(people.begin(), people.end(), comp);

    int cur = -1, accumulate = 0, pos = 0;
    for (auto &p: people) {
        if (p.first != cur) {
            accumulate = 0;
            cur = p.first;
            pos = 0;
        }
        while (pos < result.size() && (result[pos].first != -1 || accumulate < p.second)) {
            if (result[pos].first == -1)
                accumulate++;
            pos++;
        }
        result[pos++] = p;
        accumulate++;
    }
    return result;
}

int main() {
    vector<pair<int, int>> people = {{7, 0},
                                     {4, 4},
                                     {7, 1},
                                     {5, 0},
                                     {6, 1},
                                     {5, 2}};
    vector<pair<int, int>> people2 = {{2, 4},
                                      {3, 4},
                                      {9, 0},
                                      {0, 6},
                                      {7, 1},
                                      {6, 0},
                                      {7, 3},
                                      {2, 5},
                                      {1, 1},
                                      {8, 0}};
    auto rt = reconstructQueue(people2);
    for (auto p: rt) {
        cout << '[' << p.first << "," << p.second << "]" << ", ";
    }
}