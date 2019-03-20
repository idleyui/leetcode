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

int main() {
    printList(reverseBetween(mklst({1, 2, 3, 4}), 1, 2));
    printList(reverseBetween(mklst({1, 2, 3, 4}), 1, 1));
    printList(reverseBetween(nullptr, 1, 1));
}