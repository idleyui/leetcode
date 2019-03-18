#include "alg.h"

ListNode *rotateRight(ListNode *head, int k, int len = 1) {
    for (auto tail = head; tail; tail = tail->next, ++len) {
        if (!tail->next) {
            tail->next = head;
            for (k = len - k % len; k > 0; k--)head = head->next, tail = tail->next;
            tail->next = nullptr;
        }
    }
    return head;
}

ListNode *rotateRight2(ListNode *head, int k) {
    if (!head) return nullptr;

    ListNode *left = head, *right = head;

    int i = 0;
    for (; i < k && right; right = right->next, i++);

    if (!right) return rotateRight2(head, k % i);


}

ListNode *rotateRight3(ListNode *head, int k) {
    if (!head || k == 0) return head;

    ListNode *left = head, *right = head;

    int num = 1;
    for (; right->next; right = right->next, num++);

    for (int i = 0; i < num - k % num - 1; i++) {
        left = left->next;
    }

    right->next = head;
    head = left->next;
    left->next = nullptr;

    return head;
}

int main() {
    vector<ListNode *> vv = {
            mklst({1, 2, 3, 4, 5}),
            mklst({1, 2}),
            mklst({1})
    };

    for (ListNode *node: vv) {
//        for (int i = 0; i < 3; ++i) {
        int i = 2;
        printList(rotateRight3(node, i));
//        }
    }
}