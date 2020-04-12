#include "alg.h"

unordered_map<TreeNode *, unordered_set<ListNode *>> visited;

bool isSubPath(ListNode *head, ListNode *p, TreeNode *root) {
    if (!p) return true;
    if (!root) return false;
    if (visited[root].count(p)) return false;
    bool startNow = false;
    if (p->val == root->val) {
        startNow = isSubPath(head, p->next, root->left) || isSubPath(head, p->next, root->right);
    }
    bool ans = startNow || isSubPath(head, head, root->left) || isSubPath(head, head, root->right);
    if (!ans) visited[root].insert(p);
    return ans;
}

bool isSubPath(ListNode *head, TreeNode *root) {
    return isSubPath(head, head, root);
}

int main() {

}