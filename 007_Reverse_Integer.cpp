#include "alg.h"

int reverse(int x) {
    string num = to_string(x);
    num = x < 0 ? num.substr(1, num.size() - 1) : num;

    int length = num.size();
    for (int i = 0; i < length / 2; i++) swap(num[i], num[length - 1 - i]);

    try {
        return x < 0 ? (0 - stoi(num)) : stoi(num);
    } catch (const out_of_range &oor) {
        return 0;
    }
}

int main() {
    int a = 0;
    int b = 129300;
    string c = "0";
    cout << reverse(a) << "," << reverse(b) << ", " << c.find_first_not_of('0');
}