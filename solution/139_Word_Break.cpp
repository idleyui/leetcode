#include "alg.h"

bool wordBread(string s, vector<string> &wordDict) {
    vector<int> dp(s.size() + 1, 0);
    dp[0] = 1;
    unordered_set<string> wordset(wordDict.begin(), wordDict.end());
    for (int i = 1; i <= s.size(); ++i) {
        for (int j = 0; j < i; j++) {
            if (dp[j] && wordset.count(s.substr(j, i - j))) {
                dp[i] = 1;
                cout << i;

            }
            if (dp[i] == 1) break;
        }
    }
    return dp[s.size()];
}

int main() {

}