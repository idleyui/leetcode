#include "alg.h"

ListNode *merge(ListNode *l1, ListNode *l2) {
    ListNode dummy(0), *p = &dummy;
    while (l1 && l2) {
        if (l1->val < l2->val) {
            p->next = l1;
            l1 = l1->next;
        } else {
            p->next = l2;
            l2 = l2->next;
        }
        p = p->next;
    }
    p->next = l1 ? l1 : l2;
    return dummy.next;
}

ListNode *findMid(ListNode *head) {
    ListNode dummy(0), *slow = &dummy, *fast = slow;
    dummy.next = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    auto next = slow->next;
    slow->next = nullptr;
    return next;
}

ListNode *sortList(ListNode *head) {
    if (!head || !head->next) return head;
    auto midNode = findMid(head);
    return merge(sortList(head), sortList(midNode));
}

int main() {
//    printList(merge(mklst({1, 2, 3}), mklst({4, 5, 6})));
    printList(sortList(mklst({1, 3, 2, 4, 5, 3, 5})));
}