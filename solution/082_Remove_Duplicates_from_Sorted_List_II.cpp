#include "alg.h"

ListNode *deleteDuplicates(ListNode *head) {
    ListNode **p = &head;

    while ((*p)) {
        bool uniq = true;
        while ((*p)->next && (*p)->val == (*p)->next->val) {
            uniq = false;
            (*p)->next = (*p)->next->next;
        }

        if (!uniq) { *p = (*p)->next; }
        else { p = &(*p)->next; }
    }
    return head;
}

ListNode *deleteDuplicates2(ListNode *head) {
    if (!head) return head;
    int last = head->val > 0 ? 0 : 1;
    ListNode *nh = new ListNode(last), *item = head, *pre = nh;
    pre->next = head;

    bool duplicate = false;
    while (item && item->next) {
        if (item->val == item->next->val) {
            while (item->next && (item->val == item->next->val)) item = item->next;
            item = item->next;
            pre->next = item;
        } else {
            pre = item;
            item = item->next;
        }
    }

    return nh->next;
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