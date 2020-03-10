#include "alg.h"

ListNode *removeElements(ListNode *head, int val) {
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
    printList(removeElements(mklst({5, 1, 2, 3, 4, 5, 5, 3, 2, 5}), 5));
}