#include "alg.h"


class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode *root) {
        if (!root) return "";
        queue<TreeNode *> q;
        q.push(root);
        string rt = "[";
        TreeNode *next = nullptr, *last = root;

        int level_size = q.size(), cnt = 0;
        while (!q.empty()) {
            auto node = q.front();
            rt = rt + (node ? (to_string(node->val) + ",") : "null,");
            if (node) {
                q.push(node->left ? node->left : nullptr);
                q.push(node->right ? node->right : nullptr);
                if (node->left || node->right) next = node->right ? node->right : node->left;
            }
            q.pop();
            if (node == last || ++cnt == level_size) {
                if (!next) break;
                last = next;
                next = nullptr;
                level_size = q.size();
                cnt = 0;
            }
        }
        // cout << rt;
        return rt.substr(0, rt.size() - 1) + "]";
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data) {
        if (data == "") return nullptr;
        vector<TreeNode *> lst = _split(data.substr(1, data.size() - 2));
        queue<TreeNode *> q;
        q.push(lst[0]);
        for (int i = 1; i < lst.size();) {
            auto node = q.front();
            if (!node) {
                q.pop();
                continue;
            }
            if (i >= lst.size()) break;
            node->left = lst[i++];
            q.push(node->left);
            if (i >= lst.size()) break;
            node->right = lst[i++];
            q.push(node->right);
            q.pop();
        }
        return lst[0];
    }

    vector<TreeNode *> _split(string s, string delimiter = ",") {
        size_t pos = 0;
        string token;
        vector<TreeNode *> rt;
        while ((pos = s.find(delimiter)) != std::string::npos) {
            token = s.substr(0, pos);
            if (token[0] == 'n') rt.push_back(nullptr);
            else rt.push_back(new TreeNode(stoi(token)));
            s.erase(0, pos + delimiter.length());
        }
        if (s[0] == 'n') rt.push_back(nullptr);
        else rt.push_back(new TreeNode(stoi(s)));
        return rt;
    }


};

int main() {
    for (int i = 0; i < 5; ++i) {
        if (i < 5) {
            if (i > 3) break;
        }
        cout << i;
    }
}