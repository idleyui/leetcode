#include "alg.h"

ListNode *iteratively(ListNode *head) {
    if (!head) return nullptr;
    ListNode *left = head;
    ListNode *right = head->next;
    while (right) {
        left->next = nullptr;
        ListNode *tmp_left = right->next;
        right->next = left;
        left = right;
        right = tmp_left;
    }
    return left;
}

ListNode *recursively(ListNode *tail, ListNode *head = nullptr) {
    if (!tail) return nullptr;
    ListNode *new_head = recursively(tail->next, head);
    if (new_head) {
        new_head->next = tail;
        tail->next = nullptr;
    } else {
        head->next = tail;
    }
    return tail;
}

ListNode *reverseList(ListNode *head) {
    auto new_head = new ListNode(1);
    recursively(head, new_head);
    return new_head->next;
//    return iteratively(head);
}

int main() {
    auto l1 = nullptr;
    auto l2 = mklst({1});
    auto l3 = mklst({1, 2});
    printList(reverseList(l1));
    printList(reverseList(l2));
    printList(reverseList(l3));
}