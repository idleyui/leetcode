#include "alg.h"

//https://leetcode.com/problems/letter-combinations-of-a-phone-number/discuss/8064/My-java-solution-with-FIFO-queue
vector<string> letterCombinationsFIFO(string digits) {
    if (digits.empty())return {};
    string digits2str[] = {"*", "*", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    deque<string> result = {""};
    for (char c: digits) {
        int digit = c - '0';
        int current_size = result.front().size();
        while (result.front().size() == current_size) {
            string s = result.front();
            for (char c: digits2str[digit]) {
                result.push_back(s + c);
            }
            result.pop_front();
        }
    }
    return vector<string>(result.begin(), result.end());
}

vector<string> letterCombinations(string digits) {
    if (digits.size() == 0)return {};
    string arr[9]{"*", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> result = {""};
    for (char c: digits) {
        int num = c - '1';
        vector<string> new_result = {};
        for (char c1: arr[num]) {
            for (string rt: result) {
                new_result.push_back(rt + c1);
            }
        }
        result = new_result;
    }
    return result;
}


int main() {
    string s = "12345";
    vector<string> v1 = letterCombinations(s);
    cout << v1.size();
    print_container(v1);
}