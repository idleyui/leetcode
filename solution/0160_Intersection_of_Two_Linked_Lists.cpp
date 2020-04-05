#include "alg.h"

// Solution 1: cnt len first
int len(ListNode *head) {
    int cnt = 0;
    while (head) {
        cnt++;
        head = head->next;
    }
    return cnt;
}

ListNode *getIntersectionNode_1(ListNode *headA, ListNode *headB) {
    int len1 = len(headA);
    int len2 = len(headB);
    if (len1 < len2) {
        swap(headA, headB);
        swap(len1, len2);
    }
    int n = len1 - len2;
    for (int i = 0; i < n; i++) { headA = headA->next; }
    while (headA) {
        if (headA == headB) return headA;
        headA = headA->next;
        headB = headB->next;
    }
    return nullptr;
}

// Solution 2: l1 go through list 1 and list 2, l2 go through list 2 and list 1
//https://leetcode.com/problems/intersection-of-two-linked-lists/discuss/49785/Java-solution-without-knowing-the-difference-in-len!/165648
ListNode *getIntersectionNode_2(ListNode *headA, ListNode *headB) {
    ListNode *l1 = headA, *l2 = headB;

    if (!l1 || !l2) return nullptr;
    while (l1 && l2 && l1 != l2) {
        l1 = l1->next;
        l2 = l2->next;

        if (l1 == l2) return l1;

        if (l1 == nullptr) l1 = headB;
        if (l2 == nullptr) l2 = headA;
    }

    return l1;
}

// Solution 2 short version
ListNode *getIntersectionNode_3(ListNode *headA, ListNode *headB) {
    ListNode *l1 = headA, *l2 = headB;
    while (l1 != l2) {
        l1 = l1 ? l1->next : headB;
        l2 = l2 ? l2->next : headA;
    }
    return l1;
}

// Solution 3: use xor to get repeat one
// https://leetcode.com/problems/intersection-of-two-linked-lists/discuss/49899/C%2B%2B-solution-using-XOR-trick
// unbelievable trick

int main() {

}