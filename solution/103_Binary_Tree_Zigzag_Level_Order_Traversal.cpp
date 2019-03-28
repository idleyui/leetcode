#include "alg.h"

// two stacks
vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
    if (!root) return {{}};
    vector<vector<int>> vvi;
    stack<TreeNode *> s1;
    stack<TreeNode *> s2;
    s1.push(root);
    bool left = true;
    while (!s1.empty() || !s2.empty()) {
        vector<int> v;
        auto s = s1.empty() ? &s2 : &s1;
        auto s_ = s1.empty() ? &s1 : &s2;
        while (!s->empty()) {
            auto top = s->top();
            v.push_back(top->val);
            if(left) if (top->left) { s_->push(top->left); }
            if (top->right) { s_->push(top->right); }
            if(!left) if (top->left) { s_->push(top->left); }
            s->pop();
        }
        if (!v.empty()) vvi.push_back(v);
        left = !left;
    }
    return vvi;
}

int main() {
    auto tree = mk_tree({1,2,3,4,5,6,7,8,9,10});
    for(auto v: zigzagLevelOrder(tree)){
        print_container(v);
    }
}