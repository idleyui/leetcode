#include "alg.h"

ListNode *new_head;

bool equal(ListNode *head) {
    if (!head) return true;
    bool is_pal = equal(head->next) && (new_head->val == head->val);
    new_head = new_head->next;
    return is_pal;
}

// Solution 1: recursion
bool isPalindrome_1(ListNode *head) {
    new_head = head;
    return equal(head);
}

ListNode *mid(ListNode *head) {
    ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    if (fast) slow = slow->next;
    return slow;
}

ListNode *reverse(ListNode *head, ListNode *end = nullptr) {
    ListNode *new_head = nullptr, *cur = head;
    while (cur != end) {
        auto next = cur->next;
        cur->next = new_head;
        new_head = cur;
        cur = next;
    }
    return new_head;
}

// Solution 2: find mid -> reverse right -> left == right?
//https://leetcode.com/problems/palindrome-linked-list/discuss/64501/Java-easy-to-understand
bool isPalindrome_2(ListNode *head) {
    auto mid_node = mid(head);
    auto right_node = reverse(mid_node);
    while (right_node) {
        if (right_node->val != head->val) return false;
        right_node = right_node->next;
        head = head->next;
    }
    return true;
}

ListNode *mid(ListNode *head, stack<int> &stk) {
    ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
        stk.push(slow->val);
        slow = slow->next;
        fast = fast->next->next;
    }
//    odd
    if (fast) slow = slow->next;
    return slow;
}

// Solution 3 push first half into stack
bool isPalindrome_3(ListNode *head) {
    stack<int> stk;
    auto mid_node = mid(head, stk);
    while (mid_node) {
        if (stk.top() != mid_node->val) return false;
        stk.pop();
        mid_node = mid_node->next;
    }
    return true;
}

int main() {

}