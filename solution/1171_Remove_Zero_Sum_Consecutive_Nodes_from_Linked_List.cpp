#include "alg.h"

ListNode *removeZeroSumSublists(ListNode *head) {
    ListNode dummy(0), *p = &dummy;
    p->next = head;
    unordered_map<int, ListNode *> v2n;
    int accu = 0;
    int cnt = 0;
    while (p) {
        accu = accu + p->val;
        if (v2n.count(accu)) {
            v2n[accu]->next = p->next;
            cnt++;
        } else {
            v2n[accu] = p;
        }
        p = p->next;
    }
    if (!cnt) return dummy.next;
    return removeZeroSumSublists(dummy.next);
}

int main() {

}