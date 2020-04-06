#include "alg.h"

// Solution 1: dummy node
ListNode *removeElements_1(ListNode *head, int val) {
    ListNode dummy(0), *p = &dummy;
    dummy.next = head;
    while (p->next) {
        if (p->next->val == val) {
            p->next = p->next->next;
        } else {
            p = p->next;
        }
    }
    return dummy.next;
}

// Solution 2: double pointer
ListNode *removeElements_2(ListNode *head, int val) {
    ListNode **p = &head;

    while ((*p)) {
        if ((*p)->val == val) {
            *p = (*p)->next;
        } else {
            p = &(*p)->next;
        }
    }
    return head;
}

int main() {
    printList(removeElements_1(mklst({5, 1, 2, 3, 4, 5, 5, 3, 2, 5}), 5));
}