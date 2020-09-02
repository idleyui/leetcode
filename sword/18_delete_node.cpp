#include "alg.h"

ListNode *deleteNode(ListNode *head, int val) {
    ListNode dummy(0), *p = &dummy;
    p->next = head;
    while (p->next) {
        if (p->next->val == val) {
            p->next = p->next->next;
            break;
        }
        p = p->next;
    }
    return dummy.next;
}

int main() {

}