#include <iostream>
#include "cmath"
#include "debug/alg.h"

ListNode *removeNthFromEnd(ListNode *head, int n) {
    ListNode *h = new ListNode(1);
    ListNode *remove = h, *p = h;
    h->next = head;
    p = p->next;

    for (int i = 0; i < n; ++i) p = p->next;
    while (p) {
        p = p->next;
        remove = remove->next;
    }
    remove->next = remove->next->next;
    return h->next;
}

ListNode *sort(vector<ListNode *> lists) {
    ListNode head(0), *r = &head;
    while (lists.size()) {
        int min = INT_MAX;
        ListNode *p = NULL;
        int dp = 0;
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i]->val < min) {
                min = lists[i]->val;
                p = lists[i];
                dp = i;
            }
        }
        r->next = new ListNode(min);
        r = r->next;
        if (p->next == NULL)lists.erase(lists.begin() + dp);
        else lists[dp] = p->next;
    }
    return head.next;
}

ListNode *rev(ListNode *h) {
    if (!h->next)return h;
    ListNode *next = h->next;
    while (next) {
        if (h->next == next)h->next = NULL;
        ListNode *tmp = next->next;
        next->next = h;
        h = next;
        next = tmp;
    }
    return h;
}

vector<vector<int>> rv1(vector<int> v) {
    vector<vector<int>> vr{};
    for (int i = 0; i < v.size(); ++i) {
        for (int j = 0; j < v.size(); ++j) {
            if (j == i)continue;
            for (int k = 0; k < v.size(); ++k) {
                if (k == i || k == j)continue;
                vr.push_back({i + 1, j + 1, k + 1});
            }
        }
    }
    return vr;
}

int main() {
    ListNode *head = mklst({1, 2, 3, 4, 5});
    ListNode *node = removeNthFromEnd(head, 1);
    ListNode *h1 = mklst({1});
    ListNode *n1 = removeNthFromEnd(h1, 1);
    printList(n1);

    ListNode *l1 = mklst({1, 4, 5});
//    ListNode *l2 = mklst({1,3,4});
//    ListNode *l3 = mklst({2,6});
//    vector<ListNode*> v={l1,l2,l3};
//    printList(sort(v));
    printList(rev(l1));
    vector<int> v{1, 2, 3};
    for (vector<int> v1: rv1(v)) {
        print_container(v1);
    }
    return 0;
}