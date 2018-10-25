#include "alg.h"

ListNode *swapPairs(ListNode *head) {
    if (head == NULL)return NULL;
    ListNode *h = new ListNode(0);
    h->next = head;

    ListNode *p = head, *next = p->next, *pre = h;
    while (next) {
        pre->next = next;
        p->next = next->next;
        next->next = p;
        pre = p;
        p = p->next;
        if (!p)break;
        next = p->next;
    }
    return h->next;
}

int main() {
    ListNode *l1 = mklst({1, 2, 3, 4});
    ListNode *l2 = mklst({1, 2, 3});
//    ListNode *l3 = mklst({});
    printList(swapPairs(l1));
    printList(swapPairs(l2));
//    printList(swapPairs(l3));
}