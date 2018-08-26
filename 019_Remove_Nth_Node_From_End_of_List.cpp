#include "alg.h"

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};


ListNode *removeNthFromEnd(ListNode *head, int n) {
    ListNode *front = head, *remove = head;
    for (int i = 0; i < n; ++i) {
        front = front->next;
    }
    if (front == NULL)return head->next;
    else front = front->next;
    while (front != NULL) {
        front = front->next;
        remove = remove->next;
    }
    remove->next = remove->next->next;
    return head;
}

int main() {

}