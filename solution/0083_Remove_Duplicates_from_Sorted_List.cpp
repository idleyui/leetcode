#include "alg.h"

// naive code
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

// Solution 1
// https://leetcode.com/problems/remove-duplicates-from-sorted-list/discuss/28730/Concise-solution-and-memory-freeing/194583/
ListNode *deleteDuplicates_1(ListNode *head) {
    ListNode *p = head;

    while (p) {
        while (p->next && p->next->val == p->val) {
            p->next = p->next->next;
        }
        p = p->next;
    }

    return head;
}

ListNode *deleteDuplicates_2(ListNode *head) {
    ListNode *p = head;

    while (p) {
        if (p->next && p->next->val == p->val)
            p->next = p->next->next;
        else
            p = p->next;
    }
    return head;
}

// Solution 3: recursion
// https://leetcode.com/problems/remove-duplicates-from-sorted-list/discuss/28625/3-Line-JAVA-recursive-solution
ListNode *deleteDuplicates_3(ListNode *head) {
    if (!head || !head->next) return head;
    head->next = deleteDuplicates_3(head->next);
    return head->val == head->next->val ? head->next : head;
}

int main() {
    vector<vector<int>> vv = {
            {},
            {1, 2, 3},
            {1, 2, 2, 3}
    };

    for (auto v: vv) {
        printList(deleteDuplicates_3(mklst(v)));
    }

}