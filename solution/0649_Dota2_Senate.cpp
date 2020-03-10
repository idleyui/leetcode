#include "alg.h"

string predictPartyVictory(string senate) {
    int r = 0, d = 0;
    for (char c: senate) {
        if (c == 'R')r++;
        else d++;
    }

    vector<int> ban(senate.size(), 0);
    int banR = 0, banD = 0, i = 0;
    while (true) {
        if (banR == r) return "Dire";
        if (banD == d) return "Radiant";
        i = i % (int) senate.size();
        if (ban[i]) { ;
        } else if (senate[i] == 'R') {
            if (banR > 0) {
                banR--;
                ban[i] = 1;
            } else {
                banD++;
            }
        } else {
            if (banD > 0) {
                banD--;
                ban[i] = 1;
            } else {
                banR++;
            }
        }
        i++;
    }
}

// use stack
// https://leetcode.com/problems/dota2-senate/discuss/105858/JavaC%2B%2B-Very-simple-greedy-solution-with-explanation
string predictPartyVictory1(string senate){
    return "";
}

int main() {
    cout << predictPartyVictory("RD") << endl;
    cout << predictPartyVictory("RDD") << endl;
    cout << predictPartyVictory("RRRRDDDD") << endl;
    cout << predictPartyVictory("RRRRDDDDDD") << endl;
    cout << predictPartyVictory("RRRRDDDDDDD") << endl;
}