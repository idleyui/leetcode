#include "alg.h"

int len(ListNode *root) {
    int cnt = 0;
    while (root) {
        cnt++;
        root = root->next;
    }
    return cnt;
}

int plus(ListNode *l1, ListNode *l2, ListNode *&ans, int offset) {
    if (!l1) return 0;
    int sum = l1->val + (offset > 0 ? 0 : l2->val) + plus(l1->next, offset > 0 ? l2 : l2->next, ans, offset - 1);
    ListNode *left = new ListNode(sum % 10);
    left->next = ans;
    ans = left;
    return sum / 10;
}

// Solution 1: recursion
ListNode *addTwoNumbers_1(ListNode *l1, ListNode *l2) {
    int len1 = len(l1), len2 = len(l2);
    if (len1 < len2) {
        swap(len1, len2);
        swap(l1, l2);
    }

    ListNode *ans = nullptr;
    int carry = plus(l1, l2, ans, len1 - len2);
    if (carry) {
        ListNode *left = new ListNode(1);
        left->next = ans;
        ans = left;
    }
    return ans;
}

// Solution 2: use Stack
ListNode *addTwoNumbers_2(ListNode *l1, ListNode *l2) {
    stack<ListNode *> s1, s2;
    while (l1) {
        s1.push(l1);
        l1 = l1->next;
    }
    while (l2) {
        s2.push(l2);
        l2 = l2->next;
    }

    int carry = 0;
    ListNode *ans = nullptr;
    while (!s1.empty() || !s2.empty() || carry) {
        int v1 = s1.empty() ? 0 : s1.top()->val;
        int v2 = s2.empty() ? 0 : s2.top()->val;
        int sum = carry + v1 + v2;
        ListNode *head = new ListNode(sum % 10);
        head->next = ans;
        ans = head;
        carry = sum / 10;
        if (!s1.empty()) s1.pop();
        if (!s2.empty()) s2.pop();
    }
    return ans;
}

int main() {
    printList(addTwoNumbers_1(
            mklst({5, 6, 4}),
            mklst({7, 2, 4, 3})
//            mklst({})
    ));
}