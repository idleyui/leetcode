#include "alg.h"

vector<string> fizzBuzz(int n) {
    vector<string> result;
    for (int i = 1; i <= n; i++) {
        string tmp;
        if (i % 3 == 0) tmp = "Fizz";
        if (i % 5 == 0) tmp = tmp + "Buzz";
        if (tmp.empty()) tmp = to_string(i);
        result.push_back(tmp);
    }
    return result;
}

//without mod
//https://leetcode.com/problems/fizz-buzz/discuss/89931/Java-4ms-solution-Not-using-%22%22-operation
//https://leetcode.com/problems/fizz-buzz/discuss/149627/C%2B%2B-0ms-Solution-beats-100.00-without-if-else

int main() {

}