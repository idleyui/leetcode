#include "alg.h"

class Node {
public:
    int val;
    vector<Node *> neighbors;

    Node() {}

    Node(int _val, vector<Node *> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

unordered_map<Node *, Node *> visited;

Node *cloneGraph(Node *node) {
    if (visited.count(node))
        return visited[node];
    Node *newNode = new Node(node->val, {});
    visited[node] = newNode;
    for (auto p: node->neighbors) {
        newNode->neighbors.push_back(cloneGraph(p));
    }
//    set visited here will cause stackoverflow
//    Node *newNode = new Node(node->val, {});
//    visited[node] = newNode;

    return newNode;
}


int main() {
    Node one(1, {});
    Node two(2, {});
    Node three(3, {});
    Node four(4, {});
    one.neighbors.push_back(&two);
    one.neighbors.push_back(&four);
    two.neighbors.push_back(&one);
    two.neighbors.push_back(&three);
    three.neighbors.push_back(&two);
    three.neighbors.push_back(&four);
    four.neighbors.push_back(&one);
    four.neighbors.push_back(&three);
    auto node = cloneGraph(&one);
   cout << node->val;
}