#include <vector>
#include <string>
#include <iostream>
#include <climits>

using namespace std;

// define List
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

// use vector to make list
// eg: mklst({1, 2, 3})
ListNode *mklst(vector<int> v) {
    ListNode *h = new ListNode(0);
    ListNode *p = h;
    for (int i: v) {
        p->next = new ListNode(i);
        p = p->next;
    }
    return h->next;
}

// print list
void printList(ListNode *l, string spliter = ", ") {
    while (l) {
        cout << l->val << spliter;
        l = l->next;
    }
}

// remove duplicates
ListNode *uniq(ListNode *l) {
    if (!l)return l;
    ListNode *left = l, *right = l;
    int val = right->val;
    right = right->next;
    while (right) {
        if (right->val == val) {
            left->next = right->next;
        } else {
            left = right;
            val = left->val;
        }
        right = right->next;
    }
    return l;
}

// merge two list increase
ListNode *merge(ListNode *l1, ListNode *l2) {
    if (!l1 || !l2)return l1 ? l1 : l2;

    bool less = l1->val < l2->val;
    ListNode *h = less ? l1 : l2;
    h->next = less ? merge(l1->next, l2) : merge(l1, l2->next);
    return h;
}

// find node with max value
ListNode *find_max(ListNode *head) {
    ListNode *result = NULL;
    int max = INT_MIN;
    while (head) {
        if (head->val > max) result = head;
        head = head->next;
    }
    return result;
}


int main() {
//  Problem 1
    ListNode *l1 = mklst({1, 2, 5, 5});
    ListNode *l2 = mklst({2, 3, 4});
    printList(uniq(merge(l1, l2)));
//  Problem 2
    ListNode *l = mklst({1, 2, 3});
    cout << endl << find_max(l)->val;
}