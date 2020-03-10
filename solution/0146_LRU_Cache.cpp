#include "alg.h"

class LRUCache {
private:
    list<int> used;
    unordered_map<int, int> cache;
    unordered_map<int, list<int>::iterator> last_visited;
    int _capacity;

    void visit(int key) {
        auto item = last_visited.find(key);
        if (item != last_visited.end())
            used.erase(item->second);
        used.push_front(key);
        last_visited[key] = used.begin();
    }

public:
    LRUCache(int capacity) : _capacity(capacity) {}

    int get(int key) {
        auto item = cache.find(key);
        if (item == cache.end()) return -1;
        visit(key);
        return item->second;
    }

    void put(int key, int value) {
        if(cache.find(key) == cache.end() && cache.size() == _capacity) {
            cache.erase(used.back());
            last_visited.erase(used.back());
            used.pop_back();
        }
        visit(key);
        cache[key] = value;
    }
};

int main() {

}