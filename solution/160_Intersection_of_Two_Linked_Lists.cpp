#include "alg.h"

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *l1 = headA, *l2 = headB;

    if (!l1 || !l2) return nullptr;
    while (l1 && l2 && l1 != l2) {
        l1 = l1->next;
        l2 = l2->next;

        if (l1 == l2) return l1;

        if (l1 == nullptr) l1 = headB;
        if (l2 == nullptr) l2 = headA;
    }

    return l1;
}

int main() {

}