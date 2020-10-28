#include "alg.h"

// https://leetcode.com/problems/reverse-nodes-in-k-group/discuss/11457/20-line-iterative-C%2B%2B-solution
ListNode *reverseKGroup(ListNode *head, int k) {
    if (!head || k == 1) return head;
    int num = 0;
    ListNode *preh = new ListNode(-1);
    preh->next = head;
    ListNode *cur = preh, *nex, *pre = preh;
    while (cur = cur->next) num++;
    while (num >= k) {
        cur = pre->next;
        nex = cur->next;
        for (int i = 1; i < k; ++i) {
            cur->next = nex->next;
            nex->next = pre->next;
            pre->next = nex;
            nex = cur->next;
        }
        pre = cur;
        num -= k;
    }
    return preh->next;
}

ListNode *reverse(ListNode *head, ListNode *tail) {
    ListNode *nextPre = head->next;
    ListNode *p = head->next;
    head->next = tail;
    while (p != tail) {
        auto next = p->next;
        p->next = head->next;
        head->next = p;
        p = next;
    }
    return nextPre;
}

ListNode *reverseKGroup_2(ListNode *head, int k) {
    ListNode dummy(0), *t = &dummy, *h = t;
    dummy.next = head;
    while (t) {
        for (int i = 0; i < k && t; i++) t = t->next;
        if (!t) break;
        h = reverse(h, t->next);
        t = h;
    }
    return dummy.next;
}

int main() {
    auto lst = mklst({1, 2, 3, 4, 5});
    printList(reverseKGroup_2(lst, 2));
}