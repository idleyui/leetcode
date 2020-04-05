#include "alg.h"

// iteratively approach
ListNode *reverseList_1(ListNode *head) {
    ListNode *new_head = nullptr, *p = head;
    while (p) {
        ListNode *tmp = p->next;
        p->next = new_head;
        new_head = p;
        p = tmp;
    }

    return new_head;
}

// use dummy head
ListNode *reverseList_2(ListNode *head) {
    ListNode dummy(0);
    dummy.next = nullptr;
    while (head) {
        auto next = head->next;
        head->next = dummy.next;
        dummy.next = head;
        head = next;
    }
    return dummy.next;
}

//// recursively approach
//ListNode *reverseList2(ListNode *tail, ListNode *head = nullptr) {
//    if (!tail) return nullptr;
//
//
//    ListNode *new_head = recursively2(tail->next, head);
//    if (new_head) {
//        new_head->next = tail;
//        tail->next = nullptr;
//    } else {
//        head->next = tail;
//    }
//    return tail;
//}

ListNode *new_head = nullptr;

ListNode *r2(ListNode *head) {
    if (!head) return head;

    auto tail = r2(head->next);
    if (tail) {
        tail->next = head;
        head->next = nullptr;
    } else { new_head = head; }

    return head;
}

ListNode *r1(ListNode *head) {
    r2(head);
    return new_head;
}

// https://leetcode.com/problems/reverse-linked-list/discuss/58130/C%2B%2B-Iterative-and-Recursive
ListNode *r(ListNode *head) {
    if (!head || !head->next) return head;
    ListNode *node = r(head->next);
    head->next->next = head;
    head->next = NULL;
    return node;
}

int main() {
    auto l1 = nullptr;
    auto l2 = mklst({1});
    auto l3 = mklst({1, 2, 3});
//    printList(reverseList(l1));
//    printList(reverseList(l2));
//    printList(reverseList(l3));
    printList(r1(l1));
    printList(r1(l2));
    printList(r1(l3));
}