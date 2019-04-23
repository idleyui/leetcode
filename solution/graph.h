//
// Created by Leeld on 2019/4/23.
//

#ifndef LEETCODE_GRAPH_H
#define LEETCODE_GRAPH_H

#import "alg.h"

public:
int val;
vector<Node *> neighbors;

Node() {}

Node(int _val, vector<Node *> _neighbors) {
    val = _val;
    neighbors = _neighbors;
}
};

Node *mknd(string s) {
    unordered_map<int, Node *> id2nd;
    auto v = split(s);
    for (node_str: v) {
        auto vv = split(node_str);
        string sid = split(vv[0], ":")[1];
        int id = stoi(sid.substr(1, sid.size() - 2));
//        id | ref
        string neighbor_str = split(split(vv[1],":")[1]);

    }
}

#endif //LEETCODE_GRAPH_H
