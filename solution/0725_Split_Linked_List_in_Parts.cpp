#include "alg.h"

int cnt(ListNode *p) {
    int num = 0;
    for (; p; p = p->next, num++);
    return num;
}

vector<ListNode *> splitListToParts(ListNode *root, int k) {
    vector<ListNode *> result{};
    int num = order(root);
    if (num <= k) {
        for (int i = 0; i < k; ++i) {
            if (root) {
                ListNode *p = root;
                root = root->next;
                p->next = nullptr;
                result.push_back(p);
            } else {
                result.push_back({});
            }
        }
        return result;
    }

    int piece = num / k;
    int overflow = num - piece * k;


    for (int i = 0; i < k; ++i, overflow--) {
        ListNode *h = root, *p = root;
        int bound = overflow > 0 ? 1 : 0;
        for (int j = 0; j < piece + bound - 1; ++j) {
            root = root->next;
        }
        p = root;
        root = root->next;
        p->next = nullptr;
        result.push_back(h);
    }
    return result;

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