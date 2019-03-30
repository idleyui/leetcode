#include "alg.h"

class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        int size = nestedList.size();
        for (auto item = nestedList.rbegin(); item != nestedList.rend(); item++) {
            nodes.push(*item);
        }
    }

    int next() {
        auto rt = nodes.top().getInteger();
        nodes.pop();
        return rt;
    }

    bool hasNext() {
        while (!nodes.empty()) {
            auto top = nodes.top();
            if (top.isInteger())return true;

            nodes.pop();
            const vector<NestedInteger> &in = top.getList();
            for (auto item = in.rbegin(); item != in.rend(); item++)nodes.push(*item);
        }
        return false;
    }

private:
    stack<NestedInteger> nodes;
};

int main() {
    vector<int> v = {1, 2, 3};
    for (auto r = v.rbegin(); r != v.rend(); ++r) {
        cout << *r;
    }
}