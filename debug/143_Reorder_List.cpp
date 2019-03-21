#include "alg.h"

void reorderList(ListNode *head) {
    if (!head)return;
    ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
    }
//    printList(slow);

    ListNode *rh = nullptr, *cur = slow->next;
    while (cur) {
        ListNode *tmp = cur->next;
        cur->next = rh;
        rh = cur;
        cur = tmp;
    }

    slow->next = nullptr;
//    printList(rh);
//    printList(head);

    ListNode nh(-1), *p = &nh, *th = head;
    while (rh) {
        p->next = th;
        p = p->next;
        th = th->next;
        p->next = rh;
        p = p->next;
        rh = rh->next;
    }
    p->next = th;

}

int main() {
    auto lst = mklst({1, 2, 3, 4, 5, 6});
    reorderList(lst);
    printList(lst);
    auto lst1 = mklst({});
    reorderList(lst1);
    printList(lst1);
}