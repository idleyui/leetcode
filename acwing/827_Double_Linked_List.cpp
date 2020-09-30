//评测题目:
// 求最长线段
// input: [3,5] [2,4] [9,10] [-1,1]
// output: [2,5]

#include <vector>
#include <algorithm>

using namespace std;

struct Line {
    int left;
    int right;
};

void CalcMaxline(vector<Line> input, Line &output) {
    if (input.empty()) return;
    sort(input.begin(), input.end(), [](const Line &l1, const Line &l2) {
        return l1.left < l2.left || (l1.left == l2.left && l1.right < l2.right);
    });

    int max_val = 0;

    Line pre = input[0];
    for (auto line: input) {
        if (line.left <= pre.right) {
            pre.right = max(pre.right, line.right);
        } else {
            pre = line;
        }
        if (pre.right - pre.left > max_val) {
            output = pre;
            max_val = pre.right-pre.left;
        }
    }
}

int main() {

}