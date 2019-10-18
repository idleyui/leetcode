#include "alg.h"


class Trie {
private:
    struct TrieNode {
        vector<TrieNode *> childs = vector<TrieNode *>(26, nullptr);
        bool end = false;

        TrieNode() {};

        TrieNode *set(char c) {
            childs[c - 'a'] = new TrieNode();
            return childs[c - 'a'];
        }

    };

    TrieNode *root = new TrieNode();
public:
    /** Initialize your data structure here. */
    Trie() {
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        auto node = root;
        for (char c:word) {
            if (node->childs[c - 'a'])
                node = node->childs[c - 'a'];
            else {
                node = node->set(c);
            }
        }
        node->end = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        auto node = _startsWith(word);
        return node && node->end;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return _startsWith(prefix);
    }

    TrieNode *_startsWith(string prefix) {
        auto node = root;
        for (char c: prefix) {
            if (node->childs[c - 'a'])
                node = node->childs[c - 'a'];
            else
                return nullptr;
        }
        return node;
    }
};

int main() {

    Trie trie;

    trie.insert("apple");
    cout << trie.search("apple");   // returns true
    cout << trie.search("app");     // returns false
    cout << trie.startsWith("app"); // returns true
    trie.insert("app");
    cout << trie.search("app");     // returns true
}