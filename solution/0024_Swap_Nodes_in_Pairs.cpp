#include "alg.h"

// use three pointers
ListNode *swapPairs_1(ListNode *head) {
    if (!head) return nullptr;

    ListNode h(0), *left = &h;
    left->next = head;
    ListNode *mid = head, *right = mid->next;

    while (right) {
        left->next = right;
        mid->next = right->next;
        right->next = mid;

        left = mid;
        mid = mid->next;
        if (!mid) break;
        right = mid->next;
    }
    return h.next;
}

// use two pointers
ListNode *swapPairs_2(ListNode *head) {
    if (!head) return nullptr;
    ListNode h(0), *left = &h, *right = head;
    left->next = right;

    while (right && right->next) {
        left->next = right->next;
        right->next = right->next->next;
        left->next->next = right;

        left = right;
        right = right->next;
    }
    return h.next;
}

// one pointers
ListNode *swapPairs_3(ListNode *head) {
    ListNode h(0), *p = &h;
    p->next = head;
    while (p && p->next && p->next->next) {
        ListNode *tmp = p->next->next;
        p->next->next = tmp->next;
        tmp->next = p->next;
        p->next = tmp;
        p = p->next->next;
    }
    return h.next;
}

// https://leetcode.com/problems/swap-nodes-in-pairs/discuss/11019/7-8-lines-C%2B%2B-Python-Ruby
ListNode *swapPairs_4(ListNode *head) {
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
ListNode *swapPairs_5(ListNode *head) {
    if (!head || !head->next) return head;

    ListNode *tmp = head->next;
    head->next = swapPairs(tmp->next);
    tmp->next = head;

    return tmp;
}

ListNode *swapPairs_6(ListNode *head) {
    ListNode dummy1(0), dummy2(0), *p1 = &dummy1, *p2 = &dummy2;
    while (head && head->next) {
        p1->next = head;
        head = head->next;
        p2->next = head;
        head = head->next;
        p1 = p1->next;
        p2 = p2->next;
    }
    p1->next = nullptr;
    p2->next = nullptr;
    cout << "ok";
    p1 = &dummy1;
    p2 = &dummy2;
    p1 = p1->next;
    p2 = p2->next;
    ListNode dummy(0), *p = &dummy;
    while (p1) {
        p->next = p2;
        p2 = p2->next;
        p = p->next;
        p->next = p1;
        p = p->next;
        p1 = p1->next;
    }
    p->next = head;
    return dummy.next;
}

int main() {
    ListNode *l1 = mklst({1, 2, 3, 4});
    ListNode *l2 = mklst({1, 2, 3, 4, 5});
//    ListNode *l3 = mklst({});
//    printList(swapPairs(l1));
//    printList(swapPairs(l2));
//    printList(swapPairs(l3));
    printList(swapPairs7(l1));
}