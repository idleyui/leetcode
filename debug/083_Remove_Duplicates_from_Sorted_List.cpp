#include "alg.h"

ListNode *deleteDuplicates_unorder(ListNode *head) {
    unordered_set<int> val_set;
    ListNode **p = &head;

    while (*p) {
        if (val_set.count((*p)->val)) {
            ListNode *victim = *p;
            *p = (*p)->next;
            delete victim;
        } else {
            val_set.insert((*p)->val);
            p = &(*p)->next;
        }
    }

    return head;
}

// https://leetcode.com/problems/remove-duplicates-from-sorted-list/discuss/28730/Concise-solution-and-memory-freeing/194583/
ListNode *deleteDuplicates(ListNode *head) {
    ListNode *p = head;

    while (p) {
        while (p->next && p->next->val == p->val) {
            p->next = p->next->next;
        }
        p = p->next;
    }

    return head;
}

ListNode *deleteDuplicates2(ListNode *head) {
    ListNode *p = head;

    while (p) {
        if (p->next && p->next->val == p->val)
            p->next = p->next->next;
        else
            p = p->next;
    }
    return head;
}

int main() {
    vector<vector<int>> vv = {
            {},
            {1, 2, 3},
            {1, 2, 2, 3}
    };

    for (auto v: vv) {
        printList(deleteDuplicates2(mklst(v)));
    }

}