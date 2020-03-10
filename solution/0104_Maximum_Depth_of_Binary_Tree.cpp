#include "alg.h"

// Solution 1: DFS
int maxDepth(TreeNode *root) {
    if (!root) return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

// Solution 2: BFS
// https://leetcode.com/problems/maximum-depth-of-binary-tree/discuss/34207/My-code-of-C%2B%2B-Depth-first-search-and-Breadth-first-search
// just same as level order traversal and count level

int main() {

}