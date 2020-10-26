#include "alg.h"

//class LRUCache {
//private:
//    list<int> used;
//    unordered_map<int, int> cache;
//    unordered_map<int, list<int>::iterator> last_visited;
//    int capacity;
//
//    void visit(int key) {
//        auto item = last_visited.find(key);
//        if (item != last_visited.end())
//            used.erase(item->second);
//        used.push_front(key);
//        last_visited[key] = used.begin();
//    }
//
//public:
//    LRUCache(int capacity) {
//        capacity = capacity;
//    }
//
//    int get(int key) {
//        auto item = cache.find(key);
//        if (item == cache.end()) return -1;
//        visit(key);
//        return item->second;
//    }
//
//    void put(int key, int value) {
//        if (cache.find(key) == cache.end() && cache.size() == _capacity) {
//            cache.erase(used.back());
//            last_visited.erase(used.back());
//            used.pop_back();
//        }
//        visit(key);
//        cache[key] = value;
//    }
//};

struct Node {
    int key;
    int val;
    Node *next;
    Node *prev;

    Node() : key(0), val(0), next(nullptr), prev(nullptr) {}

    Node(int key, int val) : key(key), val(val), next(nullptr), prev(nullptr) {}
};

class LRUCache {
public:
    LRUCache(int capacity) : capacity(capacity), size(0) {
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (k2v.count(key)) {
            moveToHead(k2v[key]);
            return k2v[key]->val;
        }
        return -1;
    }

    void put(int key, int value) {
        if (!k2v.count(key)) {
            Node *node = new Node(key, value);
            k2v[key] = node;
            addToHead(node);
            size++;
            if (size > capacity) {
                k2v.erase(tail->prev->key);
                auto tmp = tail->prev;
                del(tmp);
                delete tmp;
                size--;
            }
        } else if (k2v[key] != head) {
            k2v[key]->val = value;
            moveToHead(k2v[key]);
        }

    }

private:
    unordered_map<int, Node *> k2v;
    Node *head, *tail;
    int size;
    int capacity;

    void addToHead(Node *node) {
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }

    void del(Node *node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void moveToHead(Node *node) {
        del(node);
        addToHead(node);
    }

};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main() {
//    LRUCache cache(2);
//
//    cache.put(1, 1);
//    cache.put(2, 2);
//    cache.get(1);       // 返回  1
//    cache.put(3, 3);    // 该操作会使得关键字 2 作废
//    cache.get(2);       // 返回 -1 (未找到)
//    cache.put(4, 4);    // 该操作会使得关键字 1 作废
//    cache.get(1);       // 返回 -1 (未找到)
//    cache.get(3);       // 返回  3
//    cache.get(4);       // 返回  4

    LRUCache cache(1);

    cache.put(2, 1);
    cache.get(2);
    cache.put(3, 2);
    cache.get(2);
    cache.get(3);
}