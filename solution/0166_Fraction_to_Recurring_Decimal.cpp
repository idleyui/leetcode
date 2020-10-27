#include "alg.h"

string fractionToDecimal(int numerator, int denominator) {
    if (numerator == 0) return "0";
    string result;

    if ((numerator > 0) ^ (denominator > 0)) result += '-';

    long long num = (long long) numerator;
    long long denom = (long long) denominator;
    num = llabs(num);
    denom = llabs(denom);
    result.append(to_string(num / denom));

    num %= denom;
    if (num == 0) return result;

    result.push_back('.');
    int idx = result.size() - 1;
    unordered_map<int, int> record;
    while (num && !record.count(num)) {
        record[num] = ++idx;
        num *= 10;
        result += to_string(num / denom);
        num %= denom;
    }

    if (record.count(num)) {
        result.insert(record[num], "(");
        result += ')';
    }
    return result;
}

int main() {

}