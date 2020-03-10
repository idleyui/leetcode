#include "alg.h"

ListNode *detectCycle(ListNode *head) {
    ListNode *slow = head, *fast = head;
    bool isCycle = false;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            isCycle = true;
            break;
        }
    }

    if (!isCycle) return nullptr;

    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}

int main() {
    cout << detectCycle(mklst_with_cycle({1, 2, 3, 4, 5, 6}, 2))->val;
}