#include "alg.h"

ListNode *new_head;

bool equal(ListNode *head) {
    if (!head) return true;
    bool is_pal = equal(head->next) && (new_head->val == head->val);
    new_head = new_head->next;
    return is_pal;
}

bool isPalindrome(ListNode *head) {
    new_head = head;
    return equal(head);
}

// find mid -> reverse right -> left == right?
bool isPalindrome2(ListNode *head) {
//    todo
    return true;
}

int main() {

}