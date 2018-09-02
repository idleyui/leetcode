#include "alg.h"

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    ListNode *p1 = l1, *p2 = l2;
    ListNode *head = new ListNode(0), *p = head;

    while (p1 && p2) {
        if (p1->val < p2->val) {
            p->next = p1;
            p1 = p1->next;
        } else if (p1->val > p2->val) {
            p->next = p2;
            p2 = p2->next;
        } else {
            p->next = p1;
            p1 = p1->next;
            p = p->next;
            p->next = p2;
            p2 = p2->next;
        }
        p = p->next;
    }
    p1 = p1 == NULL ? p2 : p1;
    p->next = p1;

    return head->next;
}

int main() {
    ListNode *l1 = mklst({});
    ListNode *l2 = mklst({1});
    ListNode *merge = mergeTwoLists(l1, l2);
    while (merge) {
        cout << merge->val << ",";
        merge = merge->next;
    }
}