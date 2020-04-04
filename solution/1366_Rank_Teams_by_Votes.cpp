#include "alg.h"

string rankTeams(vector<string> &votes) {
    int n = votes[0].size();
    vector<pair<char, vector<int>>> score(26, {'A', {}});
    for (int i = 0; i < 26; i++) score[i] = {(char) ('A' + i), vector<int>(n, 0)};
    for (string &vote: votes) {
        for (int i = 0; i < n; i++) {
            char c = vote[i];
            score[c - 'A'].second[i] += 1;
        }
    }

    sort(score.begin(), score.end(), [&n](const pair<char, vector<int>> &p1,
                                          const pair<char, vector<int>> &p2) {
        for (int i = 0; i < n; i++) {
            if (p1.second[i] == p2.second[i]) continue;
            return p1.second[i] > p2.second[i];
        }
        return p1.first < p2.first;
    });

    string ans;
    for (int i = 0; i < n; i++) { ans += score[i].first; }
    return ans;
}


int main() {

}