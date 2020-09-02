// https://www.lintcode.com/problem/plus-one-linked-list/description
#include "alg.h"

int plusone(ListNode *head) {
    if (!head) {
        return 1;
    }
    int carry = plusone(head->next);
    int sum = head->val + carry;
    head->val = sum % 10;
    return sum / 10;
}

// Solution 1: recursion
ListNode *plusOne_1(ListNode *head) {
    int carry = plusone(head);
    if (carry) {
        ListNode *one = new ListNode(1);
        one->next = head;
        return one;
    }
    return head;
}

ListNode *reverse(ListNode *head) {
    ListNode *new_head = nullptr, *cur = head;
    while (cur) {
        auto next = cur->next;
        cur->next = new_head;
        new_head = cur;
        cur = next;
    }
    return new_head;
}

// Solution 2: reverse twice
ListNode *plusOne_2(ListNode *head) {
    auto head = reverse(head);
    int carry = 1;
    ListNode dummy(0), *p = &dummy;
    dummy.next = head;
    while (p->next) {
        int sum = p->next->val + carry;
        p->next->val = sum % 10;
        carry = sum / 10;
        p = p->next;
    }
    if (carry) p->next = new ListNode(1);
    return reverse(head);
}

// Solution 3: find right->left first not 9, plus 1, right to 0
// https://www.cnblogs.com/grandyang/p/5626389.html
// 1->2->3->9->9 find 3 to 4, right to 0->0
ListNode *plusOne_3(ListNode *head) {
    ListNode *p = head, *right = nullptr;
    while (p) {
        if (p->val != 9) right = p;
        p = p->next;
    }
    if (!right) {
        ListNode *new_head = new ListNode(0);
        new_head->next = head;
        head = new_head;
        right = head;
    }
    right->val = right->val + 1;
    while (right->next) {
        right->next->val = 0;
        right = right->next;
    }
    return head;
}


int main() {

}