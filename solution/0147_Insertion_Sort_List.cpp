#include "alg.h"

ListNode *insertionSortList(ListNode *head) {
    if (!head) return nullptr;
    ListNode **cur = &head->next;
    while (*cur) {
        ListNode **insert = &head;
        while (*insert != *cur) {
            if ((*insert)->val > (*cur)->val) {
                ListNode *after_insert = *insert;
                ListNode *after_cur = (*cur)->next;
                *insert = *cur;
                (*insert)->next = after_insert;
                *cur = after_cur;
                break;
            } else {
                insert = &(*insert)->next;
            }
        }
        if (*insert == *cur) cur = &(*cur)->next;
    }
    return head;
}

ListNode *insertionSortList_2(ListNode *head) {
    if (!head) return head;
    ListNode dummy(0), *p = &dummy;
    dummy.next = head;
//  [0, p] sorted, cur to insert, next to save next to insert
    while (p->next) {
        auto cur = p->next;
        auto next = cur->next;

        for (ListNode *tmp = &dummy; tmp->next != cur; tmp = tmp->next) {
            if (tmp->next->val >= cur->val) {
                auto t = tmp->next;
                tmp->next = cur;
                cur->next = t;
                break;
            }
        }

//        if cur is the biggest
        if (cur->next == next) {
            p = cur;
        } else {
            p->next = next;
        }
    }
    return dummy.next;
}

}


int main() {
//    auto lst = mklst({1, 3, 2, 4, 5});
    auto lst = mklst({4, 2, 1, 3});
    printList(insertionSortList_2(lst));
}