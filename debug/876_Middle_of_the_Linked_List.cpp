/*
 * use two pointer, slow go 1 steps while fast go 2 steps
 * and check if fast->next exist
 */

#include "alg.h"

ListNode *middleNode(ListNode *head) {
    ListNode *slow, *fast = head;
    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

int main() {
    for (int i = 0; i < 10; ++i) {
        vector<int> v;
        for (int j = i; j < 10; ++j) {
            v.push_back(j);
        }
        print_container(v);
        printList(middleNode(mklst(v)));
    }
}