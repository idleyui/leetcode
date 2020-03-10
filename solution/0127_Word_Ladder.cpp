#include "alg.h"


bool diff(string s1, string s2) {
    int sum = 0;
    for (int i = 0; i < s1.size(); i++) {
        if (s1[i] != s2[i]) sum++;
    }
    return sum == 1;
}

int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
    wordList.push_back(beginWord);
    vector<vector<int>> dp(wordList.size(), vector<int>());
    int tgt = -1;
    for (int i = 0; i < wordList.size(); i++) {
        if (wordList[i] == endWord) tgt = i;
        for (int j = i + 1; j < wordList.size(); j++) {
            if (diff(wordList[i], wordList[j])) {
                dp[i].push_back(j);
                dp[j].push_back(i);
            }
        }
    }
    if (tgt == -1) return 0;

    vector<int> begin_list = {static_cast<int>(wordList.size() - 1)};
    unordered_set<int> visited;
    visited.insert(wordList.size() - 1);
    int len = 1;
    while (!begin_list.empty()) {
        vector<int> new_list;
        for (int begin: begin_list) {
            for (int to: dp[begin]) {
                if (to == tgt) return len + 1;
                else if (!visited.count(to)) {
                    new_list.push_back(to);
                    visited.insert(to);
                }
            }
        }
        len++;
        begin_list = new_list;
    }
    return 0;
}

int main() {

}