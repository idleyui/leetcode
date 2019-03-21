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

int main() {
//    auto lst = mklst({1, 3, 2, 4, 5});
    auto lst = mklst({1});
    printList(insertionSortList(lst));
}