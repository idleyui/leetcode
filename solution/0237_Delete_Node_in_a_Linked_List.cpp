#include "alg.h"

void deleteNode_1(ListNode *node) {
    int val = node->next->val;
    node->next = node->next->next;
    node->val = val;
}

void deleteNode_2(ListNode *node) {
    *node = *node->next;
}

int main() {

}