#include "alg.h"

int len(ListNode *head) {
    int cnt = 0;
    while (head) {
        cnt++;
        head = head->next;
    }
    return cnt;
}

vector<ListNode *> splitListToParts(ListNode *root, int k) {
    int l = len(root);
    int each_len = l / k, remainder = l % k;
    vector<ListNode *> ans;

    ListNode *group_head = root, *p = root;
    int tmp_len = 0;
    while (p) {
        tmp_len++;
        if (tmp_len == each_len + (remainder ? 1 : 0)) {
            ans.push_back(group_head);
            auto next = p->next;
            p->next = nullptr;
            p = next;
            group_head = p;
            tmp_len = 0;
            if (remainder > 0) remainder--;
        } else {
            p = p->next;
        }
    }
    int n = k - ans.size();
    for (int i = 0; i < n; i++) ans.push_back({});
    return ans;
}


int main() {
    for (auto node: splitListToParts(mklst({1, 2, 3}), 5)) {
        printList(node);
    }

    for (auto node: splitListToParts(mklst({1, 2, 3, 4, 5, 6}), 5)) {
        printList(node);
    }

    for (auto node: splitListToParts(mklst({1, 2, 3, 4, 5, 6, 7, 8, 9, 10}), 3)) {
        printList(node);
    }
}