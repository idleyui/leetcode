#include "alg.h"

// traditional method
ListNode *partition(ListNode *head, int x) {
    ListNode *lmid = new ListNode(-1), *preh = lmid;
    lmid->next = head;

    for (; lmid->next && lmid->next->val < x; lmid = lmid->next);

    ListNode *slow = lmid->next;
    ListNode *fast = slow ? slow->next : nullptr;

    while (fast) {
        if (fast->val < x) {
            slow->next = fast->next;
            fast->next = lmid->next;
            lmid->next = fast;
            lmid = lmid->next;
            fast = slow->next;
        } else {
            fast = fast->next;
            slow = slow->next;
        }
    }

    return preh->next;
}

// double list
// https://leetcode.com/problems/partition-list/discuss/29185/Very-concise-one-pass-solution
ListNode *partition2(ListNode *head, int x) {
    ListNode left(-1), right(-1);
    ListNode *lp = &left, *rp = &right;
    while (head) {
        if (head->val < x) {
            lp = lp->next = head;
        } else {
            rp = rp->next = head;
        }
        head = head->next;
    }
    lp->next = right.next;
    rp->next = nullptr;

    return left.next;
}

// double pointer
ListNode *partition3(ListNode *head, int x) {
    if (!head) return head;

    ListNode **mid = &head;
    for (; (*mid)->val < x; mid = &(*mid)->next);

    ListNode **p = &((*mid)->next);
    ListNode *tmp = nullptr;

    while (*p) {
        if ((*p)->val < x) {
            tmp = (*p)->next;
            (*p)->next = *mid;
            *mid = *p;
            p = &tmp;
//            p = &(*p)->next;
        } else {
            p = &(*p)->next;
        }
    }
    return head;
}

int main() {
    auto lst = mklst({5, 4, 2, 4, 1, 2});
    printList(partition(lst, 3));
}