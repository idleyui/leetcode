#include "alg.h"

ListNode *oddEvenList(ListNode *head) {
    int cnt = 1;
    ListNode odd_node(-1), even_node(-1);
    ListNode *odd = &odd_node, *even = &even_node;
    while (head) {
        if (cnt++ % 2 == 0) {
            even->next = head;
            even = even->next;
        } else {
            odd->next = head;
            odd = odd->next;
        }
        head = head->next;
    }
    odd->next = even_node.next;
    even->next = nullptr;
    return odd_node.next;
}

int main() {
    printList(oddEvenList(mklst({2, 1, 3, 5, 6, 4, 7})));
    printList(oddEvenList(mklst({})));
    printList(oddEvenList(mklst({1, 3, 5})));
    printList(oddEvenList(mklst({2, 4, 6})));
}