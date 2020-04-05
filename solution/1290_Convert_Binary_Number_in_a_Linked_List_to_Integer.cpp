#include "alg.h"

int getDecimalValue(ListNode *head) {
    int val = 0;
    while (head) {
        val = (val << 1) + head->val;
        head = head->next;
    }
    return val;
}

int main() {
}