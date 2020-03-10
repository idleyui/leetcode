#include "alg.h"

ListNode *reverseBetween(ListNode *head, int m, int n) {
    if (!head) return nullptr;

    ListNode lnode(-1);
    lnode.next = head;
    ListNode *left = &lnode, *right = head, *h = nullptr, *t, *cur;
    for (int i = 0; i < m - 1 && left; i++) left = left->next;
    for (int i = 0; i < n && right; i++) right = right->next;

    cur = left->next, t = cur;
    while (cur != right) {
        ListNode *tmp = cur->next;
        cur->next = h;
        h = cur;
        cur = tmp;
    }

    left->next = h;
    t->next = right;
    return lnode.next;
}

// https://leetcode.com/problems/reverse-linked-list-ii/discuss/30709/Talk-is-cheap-show-me-the-code-(and-DRAWING)
ListNode *reverseBetween2(ListNode *head, int m, int n) {
    if (!head) return nullptr;

    ListNode dummy(0), *p = &dummy;
    p->next = head;
    for (int i = 0; i < m - 1; ++i) { p = p->next; }

    ListNode *tail = p->next;

//    keep p in position m, move after tail after p
    for (int j = 0; j < n - m; ++j) {
        ListNode *tmp = p->next;
        p->next = tail->next;
        tail->next = tail->next->next;
        p->next->next = tmp;
    }

    return dummy.next;
}

ListNode *reverseBetween3(ListNode *head, int m, int n) {
    ListNode dummy(0), *p = &dummy;
    p->next = head;

    for (int i = 0; i < m - 1; i++) p = p->next;
    ListNode *tail = p->next;

    for (int i = 0; i < n - m; i++) {
        cout << tail->val << endl;
        ListNode *tmp = tail->next->next;
        tail->next->next = p->next;
        p->next = tail->next;
        tail->next = tmp;
        cout << tail->val << endl;
    }

    return dummy.next;
}

int main() {
    printList(reverseBetween3(mklst({1, 2, 3, 4, 5}), 2, 4));
    printList(reverseBetween(mklst({1, 2, 3, 4}), 1, 2));
    printList(reverseBetween(mklst({1, 2, 3, 4}), 1, 1));
    printList(reverseBetween(nullptr, 1, 1));
}