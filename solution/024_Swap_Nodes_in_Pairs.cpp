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

// https://leetcode.com/problems/swap-nodes-in-pairs/discuss/11019/7-8-lines-C%2B%2B-Python-Ruby
ListNode *swapPairs3(ListNode *head) {
    ListNode **pp = &head, *a, *b;
    while ((a = *pp) && (b = a->next)) {
        a->next = b->next;
        b->next = a;
        *pp = b;
        pp = &(a->next);
    }
    return head;
}

// https://leetcode.com/problems/swap-nodes-in-pairs/discuss/11271/Simple-implementation-with-C%2B%2B
ListNode *swapPairs2(ListNode *head) {
    if (!head || !head->next) return head;

    ListNode *tmp = head->next;
    head->next = swapPairs(tmp->next);
    tmp->next = head;

    return tmp;
}

int main() {
    ListNode *l1 = mklst({1, 2, 3, 4});
    ListNode *l2 = mklst({1, 2, 3, 4, 5});
//    ListNode *l3 = mklst({});
//    printList(swapPairs(l1));
//    printList(swapPairs(l2));
//    printList(swapPairs(l3));
    printList(swapPairs3(l2));
}