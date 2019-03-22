class Node {
public:
    int val;
    Node *prev;
    Node *next;
    Node *child;

    Node() {}

    Node(int _val, Node *_prev, Node *_next, Node *_child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};

// save tail in head->prev
Node *flatten(Node *head) {
    Node *p = head;
    while (p) {
        if (p->child) {
            Node *child_head = flatten(p->child);
            p->child = nullptr;
            Node *child_tail = child_head->prev;
            Node *p_next = p->next;
            p->next = child_head;
            child_head->prev = p;
            child_tail->next = p_next;
            if (p_next) p_next->prev = child_tail;
            else head->prev = child_tail;
            p = p_next;
        } else {
            if (!p->next) {
                head->prev = p;
            }
            p = p->next;
        }
    }
    return head;
}

#include "alg.h"

int main() {


}