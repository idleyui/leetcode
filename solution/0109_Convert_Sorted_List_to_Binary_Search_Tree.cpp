#include "alg.h"

// approach 1: recursion
TreeNode *sortedListToBST_1(ListNode *head) {
    if (!head)return nullptr;
    ListNode *fast = head, *slow = head, *preslow = nullptr;
    while (fast && fast->next) {
        fast = fast->next->next;
        preslow = slow;
        slow = slow->next;
    }

    if (preslow) preslow->next = nullptr;

    TreeNode *root = new TreeNode(slow->val);
    if (head == slow) return root;

    root->left = sortedListToBST(head);
    root->right = sortedListToBST(slow->next);
    return root;
}

ListNode *mid(ListNode *head, ListNode *tail) {
    ListNode dummy(0), *slow = &dummy, *fast = slow;
    dummy.next = head;
    while (fast != tail && fast->next != tail) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

TreeNode *sortedListToBST_2(ListNode *head, ListNode *tail = nullptr) {
    if (head == tail) return nullptr;
    auto midNode = mid(head, tail);
    TreeNode *root = new TreeNode(midNode->val);
    root->left = sortedListToBST(head, midNode);
    root->right = sortedListToBST(midNode->next, tail);
    return root;
}

// approach 2: recursion + conversion to array
vector<int> values = {};

TreeNode *sortedListToBST_3(int low, int high) {
    if (low > high) return nullptr;
    int mid = (low + high) / 2;
    TreeNode *root = new TreeNode(values[mid]);

    root->left = sortedListToBST2(low, mid - 1);
    root->right = sortedListToBST2(mid + 1, high);

    return root;
}

TreeNode *sortedListToBST_3(ListNode *head) {
    if (!head) return nullptr;

    for (; head; head = head->next) values.push_back(head->val);

    return sortedListToBST2(0, values.size() - 1);
}

// approach 3: inorder simulation
TreeNode *sortedListToBST3(ListNode *head) {

}

int main() {
    auto root1 = sortedListToBST_1(mklst({1, 3, 4, 5}));
    auto root2 = sortedListToBST_1(mklst({1, 3, 4, 5}));
    print_tree(root1);
    print_tree(root2);
}