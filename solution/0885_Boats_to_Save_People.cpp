#include "alg.h"

int numRescueBOats(vector<int> &people, int limit) {
    sort(people.begin(), people.end());
    int count = 0, i = 0, j = people.size() - 1;
    while (i < j) {
        if (people[i] >= limit) {
            count += people.size();
            break;
        } else if (people[j] >= limit || (people[i] + people[j]) > limit) {
            j--;
        } else {
            i++;
            j--;
        }
        count += 1;
    }
    return i == j ? count + 1 : count;
}

int main() {
    vector<pair<vector<int>, int>> v = {
            {{1, 2},       3},
            {{3, 2, 2, 1}, 3},
            {{3, 5, 3, 4}, 5},
            {{1, 2, 3, 4}, 3},
    };

    for (pair<vector<int>, int> &vc: v) {
        cout << numRescueBOats(vc.first, vc.second) << ", ";
    }
}