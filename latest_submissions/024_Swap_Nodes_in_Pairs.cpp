/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL)return NULL;
    ListNode *h = new ListNode(0);
    h->next = head;

    ListNode *p = head, *next = p->next, *pre = h;
    while (next) {
        pre->next = next;
        p->next = next->next;
        next->next = p;
        pre = p;
        p = p->next;
        if (!p)break;
        next = p->next;
    }
    return h->next;
    }
};