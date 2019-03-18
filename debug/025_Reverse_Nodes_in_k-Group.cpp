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
        for (int i = 0; i < k; ++i) {
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

int main() {

}