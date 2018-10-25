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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode h(0);
        // ListNode *h = new ListNode(0);
        h.next = head;
        ListNode *p = h.next, *remove = &h;
        
        for(int i = 0; i < n;i++) p=p->next;
        
        while(p){
            p=p->next;
            remove=remove->next;
        }
        remove->next = remove->next->next;
        return h.next;
    }
};