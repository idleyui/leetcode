#include "alg.h"

// do not use one loop
// two loop
string getHint(string secret, string guess) {
    vector<int> cnt(10, 0);
    for (char c: secret) cnt[c - '0']++;
    int bulls = 0, cows = 0;
    for (int i = 0; i < guess.size(); i++) {
        if (guess[i] == secret[i]) {
            bulls++;
            cnt[guess[i] - '0']--;
        }
    }
    for (int i = 0; i < guess.size(); i++) {
        if (cnt[guess[i] - '0'] == 0 || guess[i] == secret[i]) continue;
        cows++;
        cnt[guess[i] - '0']--;
    }
    return to_string(bulls) + 'A' + to_string(cows) + 'B';
}

// one loop
string getHint_2(string secret, string guess) {
    vector<int> secret_cnt(10, 0);
    vector<int> guess_cnt(10, 0);
    int bulls = 0, cows = 0;
    for (int i = 0; i < guess.size(); i++) {
        if (guess[i] == secret[i]) {
            bulls++;
        } else {
            if (secret_cnt[guess[i] - '0']) {
                cows++;
                secret_cnt[guess[i] - '0']--;
            } else {
                guess_cnt[guess[i] - '0']++;
            }
            if (guess_cnt[secret[i] - '0']) {
                cows++;
                guess_cnt[secret[i] - '0']--;
            } else {
                secret_cnt[secret[i] - '0']++;
            }
        }
    }
    return to_string(bulls) + 'A' + to_string(cows) + 'B';
}

// one loop and one state array
// https://leetcode.com/problems/bulls-and-cows/discuss/74621/One-pass-Java-solution
string getHint_3(string secret, string guess) {
    vector<int> cnt(10, 0);
    int bulls = 0, cows = 0;
    for (int i = 0; i < secret.size(); i++) {
        if (secret[i] == guess[i]) bulls++;
        else{
            if(cnt[secret[i]-'0'] < 0)  cows++;
            if(cnt[guess[i]-'0'] > 0)   cows++;
            cnt[secret[i]-'0']++;
            cnt[guess[i]-'0']--;
        }
    }
    return to_string(bulls) + 'A' + to_string(cows) + 'B';
}

int main() {

}