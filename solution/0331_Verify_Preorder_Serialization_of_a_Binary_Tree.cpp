#include "alg.h"

bool isValidSerialization(string preorder) {
    auto v = split(preorder);
    stack<string> nums;
    for (auto &s:v) {
        if (!nums.empty() && s == "#") {
            if (nums.top() != "#") {
                nums.push("#");
            } else {
                while (!nums.empty() && nums.top() == "#") {
                    nums.pop();
                    if (!nums.empty() && nums.top() != "#") nums.pop();
                    else return false;
                }
                nums.push("#");
            }
        } else {
            nums.push(s);
        }
    }
    return nums.size() == 1 && nums.top() == "#";
}

int main() {
    auto vs = {
            "9,3,4,#,#,1,#,#,2,#,6,#,#",
            "1,#,#",
            "#",
            "#,#",
            "1,#,#,#,#",
            "1,#",
            "9,#,#,1"
    };
    for (auto s: vs) {
        cout << isValidSerialization(s) << ",";
    }
//    print_container(split(s));
}