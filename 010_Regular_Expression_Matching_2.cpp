#include "alg.h"


bool dp(int i, int j, string s, string p, int **match) {
    if (match[i][j] != 0) return match[i][j] == 1;
    bool m = false;
    if (j == p.size()){
        m = i == s.size();
    } else{
        bool first_match = s[i] ==
    }

}

bool isMatch(string s, string p) {
    int **match = new int *[s.size() + 1];
    for (int i = 0; i < s.size() + 1; i++)match[i] = new int[p.size() + 1]();
    return dp(0, 0, s, p, match);
}


int main() {
    isMatch("sdf", "s");
}