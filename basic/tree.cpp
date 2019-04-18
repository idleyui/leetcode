#include "../solution/alg.h"

unordered_map<TreeNode *, int> visited;

int num(TreeNode *root) {
    if (!root) return 0;
    if (visited.count(root)) {
        return visited[root];
    }
    int visit_root = root->val;
    if (root->left)
        visit_root += (num(root->left->left) + num(root->left->right));
    if (root->right)
        visit_root += (num(root->right->left) + num(root->right->right));

    int not_visit_root = num(root->left) + num(root->right);

    int val = max(visit_root, not_visit_root);
    visited[root] = val;
    return val;
}

int main() {
    auto root = mk_tree({1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13});
    auto root1 = mk_tree({1, 2, 3});
    cout << num(root);
    cout << num(root1);
}