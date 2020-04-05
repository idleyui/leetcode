#include "alg.h"

//https://leetcode.com/problems/middle-of-the-linked-list/discuss/154619/C%2B%2BJavaPython-Slow-and-Fast-Pointers
ListNode *middleNode(ListNode *head) {
    ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// choose first middle node
// [1,2,3,4] choose 2
ListNode *middleNode_first(ListNode *head) {
    ListNode dummy(0), *slow = &dummy, *fast = slow;
    dummy.next = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int main() {
    for (int i = 0; i < 5; ++i) {
        vector<int> v;
        for (int j = i; j < 10; ++j) {
            v.push_back(j);
        }
        print_container(v);
        cout << "find first middle node: ";
        cout << middleNode_first(mklst(v))->val << endl;
        cout << "find second middle node: ";
        cout << middleNode(mklst(v))->val << endl;
    }
}