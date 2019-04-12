#include "alg.h"

ListNode *deleteDuplicates(ListNode *head) {
    ListNode **p = &head;
    while (*p && (*p)->next) {
        if ((*p)->val == (*p)->next->val) {
            int val = (*p)->val;
            while (*p && (*p)->val == val) { *p = (*p)->next; }
        } else {
            p = &((*p)->next);
        }
    }
    return head;
}

ListNode *deleteDuplicates2(ListNode *head) {
    ListNode h(0), *p = &h;
    p->next = head;

    while (p->next && p->next->next) {
        if (p->next->val == p->next->next->val) {
            int val = p->next->val;
            while (p->next && p->next->val == val) p->next = p->next->next;
        } else {
            p = p->next;
        }
    }

    return h.next;
}

int main() {
    vector<vector<int>> vv{
            {},
            {1, 2, 3},
            {1, 1, 2, 3, 3, 4, 4, 5}
    };

    for (auto v: vv) {
        printList(deleteDuplicates(mklst(v)));
    }

}