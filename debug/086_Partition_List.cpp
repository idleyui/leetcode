#include "alg.h"

ListNode *partition(ListNode *head, int x) {
    if (!head) return head;

    ListNode **mid = &head;
    for (; (*mid)->val < x; mid = &(*mid)->next);

    ListNode **p = &((*mid)->next);
    ListNode *tmp = nullptr;

    while (*p) {
        if ((*p)->val < x) {
            tmp = (*p)->next;
            (*p)->next = *mid;
            *mid = *p;
            p = &tmp;
//            p = &(*p)->next;
        } else {
            p = &(*p)->next;
        }
    }
    return head;
}

int main() {
    auto lst = mklst({5, 4, 2, 4, 1, 2});
    printList(partition(lst, 3));
}