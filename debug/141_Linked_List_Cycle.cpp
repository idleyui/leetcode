#include "alg.h"

bool hasCycle(ListNode *head) {
    ListNode *slow = head, *fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (fast == slow) return true;
    }

    return false;
}

int main() {
    cout << hasCycle(mklst_with_cycle({1, 2, 3}, 0));
    cout << hasCycle(mklst({1, 2, 3}));
}