#include "alg.h"

ListNode *mklst(vector<ListNode *> &list) {
    auto item = list.begin();
    for (; item != list.end(); item++) {
        (*item)->next = *(item + 1);
    }
    *item = nullptr;
    return list[0];
}

ListNode *ml_brute_force(vector<ListNode *> &lists) {
    vector<ListNode *> nodes;
    for (auto list: lists) {
        while (list) {
            nodes.push_back(list);
            list = list->next;
        }
    }
    sort(nodes.begin(), nodes.end(), compareListNode);
    return mklst(nodes);
}

ListNode *ml_one_by_one(vector<ListNode *> &lists) {
    ListNode h(0), *p = &h;
    auto minode = new ListNode(INT_MAX);
    while (true) {
        ListNode **min = &minode;
        for (auto &head: lists) {
//            not work edition
//            if (head && (head->val < (*min)->val)) { (*min) = head; }
            if (head && (head->val < (*min)->val)) { min = &head; }
        }
        if ((*min)->val == INT_MAX)break;
        p->next = *min;
        *min = (*min)->next;
        p = p->next;
    }
    return h.next;
}

ListNode *ml_priority_queue(vector<ListNode *> &lists) {
//    priority_queue<
//    for (auto p: lists) {
//        while (p) {
//
//        }
//    }
// todo
    return nullptr;
}

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    if (!l1 || l2 && l1->val > l2->val) swap(l2, l1);
    if (l1) l1->next = mergeTwoLists(l1->next, l2);
    return l1;
}

ListNode *ml_merge_one_by_one(vector<ListNode *> &lists) {
    if (lists.size() == 0) return nullptr;
    ListNode *p = lists[0];
    for (auto item = lists.begin() + 1; item != lists.end(); item++) {
        p = mergeTwoLists(p, *item);
    }
    return p;
}

// https://leetcode.com/problems/merge-k-sorted-lists/discuss/10531/Sharing-my-straightforward-C%2B%2B-solution-without-data-structure-other-than-vector
ListNode *merge_divide_and_conquer(vector<ListNode *> &lists) {
// todo
}

int main() {
    vector<vector<int>> vv = {
            {1, 4, 5},
            {1, 3, 4},
            {2, 6}
    };
    vector<ListNode *> list;
    for (auto &v: vv) { list.push_back(mklst(v)); }

//    printList(ml_brute_force(list));
//    printList(ml_one_by_one(list));
    printList(ml_merge_one_by_one(list));
}