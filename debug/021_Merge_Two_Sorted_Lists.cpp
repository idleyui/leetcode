#include "alg.h"

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    ListNode *p1 = l1, *p2 = l2;
    ListNode *head = new ListNode(0), *p = head;

    while (p1 && p2) {
        if (p1->val > p2->val) swap(p1, p2);

        p->next = p1;
        p1 = p1->next;
        p = p->next;
    }

    p->next = p1 ? p1 : p2;
    return head->next;
}

// https://leetcode.com/problems/merge-two-sorted-lists/discuss/9814/3-lines-C%2B%2B-(12ms)-and-C-(4ms)
ListNode *mergeTwoLists_2(ListNode *l1, ListNode *l2) {
    if (!l1 || l2 && l1->val > l2->val) swap(l2, l1);
    if (l1) l1->next = mergeTwoLists_2(l1->next, l2);
    return l1;
}

// https://leetcode.com/problems/merge-two-sorted-lists/discuss/9715/Java-1-ms-4-lines-codes-using-recursion
ListNode *mergeTwoList_3(ListNode *l1, ListNode *l2) {
    if (!l1) return l2;
    if (!l2) return l1;
    if (l1->val > l2->val) return mergeTwoList_3(l2, l1);
    l1->next = mergeTwoList_3(l1->next, l2);
    return l1;
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