#include "alg.h"

ListNode *removeNthFromEnd(ListNode *head, int n) {
    ListNode h(0);
    h.next = head;
    ListNode *front = h.next, *remove = &h;

    for (int i = 0; i < n; ++i) { front = front->next; }

    while (front) {
        front = front->next;
        remove = remove->next;
    }

    ListNode *victim = remove->next;
    remove->next = remove->next->next;
    delete victim;
    return h.next;
}

// double pointer trick
// https://leetcode.com/problems/remove-nth-node-from-end-of-list/discuss/8812/My-short-C%2B%2B-solution
ListNode *removeNthFromEnd2(ListNode *head, int n) {
    ListNode **t1 = &head, *t2 = head;
    for (int i = 0; i < n; ++i) t2 = t2->next;
    while (t2) {
        t1 = &((*t1)->next);
        t2 = t2->next;
    }
    ListNode *victim = *t1;
    *t1 = (*t1)->next;
    delete victim;
    return head;
}

// from linus torvalds teds talk: https://youtu.be/o8NPllzkFhE
// https://www.cnblogs.com/qwertWZ/archive/2013/02/10/2909699.html
// https://grisha.org/blog/2013/04/02/linus-on-understanding-pointers/
// https://stackoverflow.com/questions/22121257/how-do-i-properly-delete-nodes-of-linked-list-in-c
// http://blogread.cn/it/article/6243?f=wb
void remove_list_entry(ListNode *head, ListNode *entry) {
    ListNode **indirect = &head;
    while ((*indirect) != entry)
        indirect = &(*indirect)->next;

    *indirect = entry->next;
    free(entry);
}

int main() {
    ListNode *head = mklst({1, 2, 3});

//    remove_list_entry(head, head->next);

//    removeNthFromEnd(head, 2);
//    removeNthFromEnd2(head, 2);

    printList(head);
}