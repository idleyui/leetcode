#include "alg.h"

class Node {
public:
    int val;
    Node *next;
    Node *random;

    Node() {}

    Node(int _val, Node *_next, Node *_random) {
        val = _val;
        next = _next;
        random = _random;
    }
};

// Solution 1: loop twice
// https://leetcode.com/problems/copy-list-with-random-pointer/discuss/43488/Java-O(n)-solution
Node *copyRandomList1(Node *head) {
    unordered_map<Node *, Node *> src2des;
    Node *p = head;
    while (p) {
        src2des[p] = new Node(p->val, nullptr, nullptr);
        p = p->next;
    }
    p = head;
    while (p) {
        src2des[p]->next = src2des[p->next];
        src2des[p]->random = src2des[p->random];
        p = p->next;
    }
    return src2des[head];
}

// Solution 2: O(1) side-by-side solution
// https://leetcode.com/problems/copy-list-with-random-pointer/discuss/43491/A-solution-with-constant-space-complexity-O(1)-and-linear-time-complexity-O(N)
// algorithm 1 in https://leetcode.com/problems/copy-list-with-random-pointer/discuss/43497/2-clean-C%2B%2B-algorithms-without-using-extra-arrayhash-table.-Algorithms-are-explained-step-by-step.
Node *copyRandomList2(Node *head) {
    Node *p = head;

    // insert copy after src
    while (p) {
        auto next = p->next;
        auto copy = new Node(p->val, nullptr, nullptr);
        p->next = copy;
        copy->next = next;
        p = next;
    }
    p = head;

    // assign random
    while (p) {
        if (p->random)
            p->next->random = p->random->next;
        p = p->next->next;
    }

    // link copy
    p = head;
    Node dummy(0, nullptr, nullptr), *new_p = &dummy;
    while (p) {
        new_p->next = p->next;
        new_p = new_p->next;
        p->next = new_p->next;
        p = p->next;
    }
    return dummy.next;

}

// Solution 3
// algorithm 2 in https://leetcode.com/problems/copy-list-with-random-pointer/discuss/43497/2-clean-C%2B%2B-algorithms-without-using-extra-arrayhash-table.-Algorithms-are-explained-step-by-step.

int main() {

}