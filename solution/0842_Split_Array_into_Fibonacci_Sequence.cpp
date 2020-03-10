#include "alg.h"

vector<int> splitIntoFibonacci(string S) {
    int n = S.size();
    if (n == 0)return {};
    vector<int> result;
    bool b = true;
    for (int len = 1; len <= n - 2; ++len) {
        if (len > 1 && S[0] == '0')break;
        b = true;
        int left = 0;
        try {
            left = stoi(S.substr(0, len));
        } catch (const exception &e) {
            break;
        }
        result.clear();
        result.push_back(left);
        for (int rlen = 1; rlen <= n - len - 1; ++rlen) {
            int mid = 0;
            try {
                mid = stoi(S.substr(len, rlen));
            } catch (const exception &e) {
                b = false;
                break;
            }
            left = result[0];
            result.clear();
            result.push_back(left);
            result.push_back(mid);
            b = true;
            int s = 0;
            for (int i = len + rlen; i < n; i += s) {
                //todo check overflow
                if (INT_MAX - left < mid) {
                    b = false;
                    break;
                }
                string sum = to_string(mid + left);
                s = sum.size();
                if (s + i > n) {
                    b = false;
                    break;
                }
                string mid_str = S.substr(i, s);
                if (mid_str != sum) {
                    b = false;
                    break;
                }
                left = mid;
                mid = stoi(mid_str);
                result.push_back(mid);
            }
            if (b)break;
        }
        if (b)break;
    }
    return (b && result.size() > 2) ? result : vector<int>();
}

int main() {
    print_container(splitIntoFibonacci("0000"));
    print_container(splitIntoFibonacci("123456579"));
    print_container(splitIntoFibonacci("11235813"));
    print_container(splitIntoFibonacci("112358130"));
    print_container(splitIntoFibonacci("0123"));
    print_container(splitIntoFibonacci("0224"));
    print_container(splitIntoFibonacci("1101111"));
    print_container(splitIntoFibonacci("214748364721474836422147483641"));
    print_container(splitIntoFibonacci("214748364721474836422147483641"));
}