// ref: https://leetcode.com/problems/add-two-numbers/discuss/997/c++-Sharing-my-11-line-c++-solution-can-someone-make-it-even-more-concise
#include "alg.h"

// carry, l1, l2, p
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode dummy(0), *p = &dummy;
    int carry = 0;

    while (l1 || l2 || carry) {
        int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
        carry = sum / 10;
        p->next = new ListNode(sum % 10);
        p = p->next;

        l1 = l1 ? l1->next : l1;
        l2 = l2 ? l2->next : l2;
    }

    return dummy.next;
}
