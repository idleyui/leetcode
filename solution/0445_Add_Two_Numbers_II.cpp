#include "alg.h"

int cnt(ListNode *l) {
    int r = 0;
    while (l) {
        l = l->next;
        r++;
    }
    return r;
}

ListNode *result = nullptr;

int r(ListNode *l1, ListNode *l2, int shift) {
    if (!l1) return 0;

    int bound = shift ? r(l1->next, l2, shift - 1) : r(l1->next, l2->next, shift);
    int sum = shift ? (l1->val + bound) : (l1->val + l2->val + bound);
    ListNode *node = new ListNode(sum % 10);
    node->next = result;
    result = node;
    return sum / 10;
}

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    int len1 = order(l1), len2 = order(l2);
    if (len1 < len2) {
        swap(l1, l2);
        swap(len1, len2);
    }

    int bound = r(l1, l2, len1 - len2);
    if (bound) {
        ListNode *p = new ListNode(bound);
        p->next = result;
        result = p;
    }
    return result;
}

int main() {
    printList(addTwoNumbers(
            mklst({5, 6, 4}),
            mklst({7, 2, 4, 3})
//            mklst({})
    ));
}