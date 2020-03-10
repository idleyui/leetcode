#include "alg.h"

void deleteNode(ListNode *node) {
    int val = node->next->val;
    node->next = node->next->next;
    node->val = val;
}

void deleteNode2(ListNode *node) {
    *node = *node->next;
}

int main() {

}