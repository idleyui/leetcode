#include "alg.h"

ListNode *merge(ListNode *l1, ListNode *l2) {
    ListNode h(0), *head = &h;
    while (l1 || l2) {
        bool left = (l1 ? l1->val : INT_MAX) <= (l2 ? l2->val : INT_MAX);
        head->next = left ? l1 : l2;
        head = head->next;
        l1 = left ? l1->next : l1;
        l2 = left ? l2 : l2->next;
    }
    return h.next;
}

ListNode *sortList(ListNode *head) {
    if (!head || !head->next) return head;
    ListNode *slow = head, *fast = head->next;
    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
    }

    auto rhead = slow->next;
    slow->next = nullptr;
    auto l1 = sortList(head);
    auto l2 = sortList(rhead);

    return merge(l1, l2);
}

int main() {
//    printList(merge(mklst({1, 2, 3}), mklst({4, 5, 6})));
    printList(sortList(mklst({1, 3, 2, 4, 5, 3, 5})));
}