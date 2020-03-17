#include "alg.h"

string licenseKeyFormatting(string S, int K) {
    string rt = "";
    int cnt = 0;
    for (int i = S.size() - 1; i >= 0; i--) {
        if (S[i] == '-') continue;
        if (cnt == K) {
            rt += '-';
            cnt = 0;
        }
        rt += toupper(S[i]);
        cnt++;
    }
    reverse(rt.begin(), rt.end());
    return rt;
}


// memory overflow
string licenseKeyFormatting_error(string S, int K) {
    string rt = "";
    int cnt = 0;
    for (int i = S.size() - 1; i >= 0; i--) {
        if (S[i] == '-') continue;
        if (cnt == K) {
            rt = '-' + rt;
            cnt = 0;
        }
        rt = (char) toupper(S[i]) + rt;
        cnt++;
    }
    return rt;
}

int main() {

}