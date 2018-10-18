#include "alg.h"

ListNode *uniq(ListNode *l) {
    if (!l)return l;
    ListNode *left = l, *right = l;
    int val = right->val;
    right = right->next;
    while (right) {
        if (right->val == val) {
            left->next = right->next;
        } else {
            left = right;
            val = left->val;
        }
        right = right->next;
    }
    return l;
}

ListNode *merge(ListNode *l1, ListNode *l2) {
    if (!l1 || !l2)return l1 ? l1 : l2;

    bool less = l1->val < l2->val;
    ListNode *h = less ? l1 : l2;
    h->next = less ? merge(l1->next, l2) : merge(l1, l2->next);
    return h;
}

ListNode *find_max(ListNode *head) {
    ListNode *result = NULL;
    int max = INT_MIN;
    while (head) {
        if (head->val > max) result = head;
        head = head->next;
    }
    return result;
}


int main() {
    ListNode *l1 = mklst({1, 2, 5, 5});
    ListNode *l2 = mklst({2, 3, 4});
    printList(uniq(merge(l1, l2)));
    ListNode *l = mklst({1, 2, 3});
    cout << endl << find_max(l)->val;
}