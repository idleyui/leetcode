#include "alg.h"

class Node {
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() {}

    Node(int _val, Node *_left, Node *_right, Node *_next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};

Node *connect(Node *root) {
    if (!root) return root;
    queue<Node *> q;
    q.push(root);
    int cnt = 0, child = 1;
    Node *before = nullptr, *p = nullptr;
    while (!q.empty()) {
        if (cnt < child) {
            p = q.front();
            if (p->left) q.push(p->left);
            if (p->right) q.push(p->right);
            if (before) before->next = p;
            before = p;
            q.pop();
            cnt++;
        } else {
            before->next = nullptr;
            before = nullptr;
            child = q.size();
            cnt = 0;
        }
    }
    return root;

}

int main() {

}