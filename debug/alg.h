//
// Created by leelddd on 8/2/2018.
//

#ifndef LEETCODE_ALG_H
#define LEETCODE_ALG_H

#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <iterator>
#include <bits/stdc++.h>
#include <cmath>
#include <numeric>

using namespace std;

vector<int> mkv(vector<int> v) {
    return v;
}

vector<vector<int>> mkvv(vector<vector<int>> vv) {
    return vv;
}


template<typename T>
void print_container(const T &container) {
    std::copy(std::begin(container),
              std::end(container),
              std::ostream_iterator<typename T::value_type>(cout, " "));
    cout << endl;
}

template<typename T>
void print_container(const T &container, const char *spliter) {
    std::copy(std::begin(container),
              std::end(container),
              std::ostream_iterator<typename T::value_type>(cout, spliter));
}

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *mklst(vector<int> v) {
    ListNode *h = new ListNode(0);
    ListNode *p = h;
    for (int i: v) {
        p->next = new ListNode(i);
        p = p->next;
    }
    return h->next;
}

void printList(ListNode *l, string spliter = ", ") {
    while (l) {
        cout << l->val << spliter;
        l = l->next;
    }
}

struct Point {
    int x;
    int y;

    Point() : x(0), y(0) {}

    Point(int a, int b) : x(a), y(b) {}
};

#endif //LEETCODE_ALG_H
