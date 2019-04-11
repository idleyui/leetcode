#include "alg.h"

// https://leetcode.com/problems/simplify-path/discuss/25680/C%2B%2B-10-lines-solution
// 1. split by /
// 2. handle special case("", ".", "..") and common case
// 3. make new path by path items
string simplifyPath(string path) {
    string res, tmp;
    vector<string> paths;
    stringstream ss(path);
    while (getline(ss, tmp, '/')) {
        if (tmp == "" || tmp == ".") continue;
        else if (tmp == ".." && !paths.empty())paths.pop_back();
        else if (tmp != "..") paths.push_back(tmp);
    }
    for (auto str: paths) res += '/' + str;
    return res.empty() ? "/" : res;
}

int main() {
    cout << simplifyPath("/home/") << endl;
    cout << simplifyPath("/../") << endl;
    cout << simplifyPath("/home//foo/") << endl;
    cout << simplifyPath("/a/../../b/../c//.//") << endl;
    cout << simplifyPath("/a//b////c/d//././/..") << endl;
}