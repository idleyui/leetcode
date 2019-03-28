#include "alg.h"

bool is_name(char c) {
    return c != '/' && c != '.';
}

//https://leetcode.com/problems/simplify-path/discuss/25680/C%2B%2B-10-lines-solution
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