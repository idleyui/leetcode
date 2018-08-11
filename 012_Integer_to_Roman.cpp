#include "alg.h"

vector<int> value = {1000, 500, 100, 50, 10, 5, 1};
vector<int> rvalue = {0, 900, 400, 90, 40, 9, 4};
vector<string> reverse_str = {"", "CM", "CD", "XC", "XL", "IX", "IV"};
string symbol = "MDCLXVI";

string intToRoman(int num) {
    string roman = "";
    for (int i = 0; i < value.size() && num != 0; ++i) {
        if (rvalue[i] != 0 && num >= rvalue[i]) {
            roman += reverse_str[i];
            num -= rvalue[i];
        } else {
            int count = num / value[i];
            for (int j = 0; j < count; ++j) roman += symbol[i];
            num %= value[i];
        }
    }
    return roman;
}

int main() {
    vector<int> test_value = {1, 3, 4, 9, 58, 1994, 3999};
    for (int i:test_value) {
        cout << intToRoman(i) << ",";
    }
}