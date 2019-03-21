#include "alg.h"

Node *copyRandomList(Node *head) {
    if (!head) return nullptr;
//    unordered_map<int, vector<Node *>> id2random{};
    unordered_map<int, Node *> id2node{};

    Node pre(-1, nullptr, nullptr), *new_head = &pre;
//    Node *new_head = new Node(head->val, head->next, head->random), *p = head;
    while (head) {
        if (id2node.count(head->val)) {
            new_head->next = id2node[head->val];
        } else {
            new_head->next = new Node(head->val, nullptr, nullptr);
            id2node[head->val] = new_head->next;
        }
        new_head = new_head->next;

        if (head->random) {
            int rand_val = head->random->val;
            if (id2node.count(rand_val)) {
                new_head->random = id2node[rand_val];
            } else {
                Node *random = new Node(rand_val, nullptr, nullptr);
                new_head->random = random;
                id2node[rand_val] = random;
            }
        }

        head = head->next;
    }
    return pre.next;
}

int main() {

}