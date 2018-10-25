/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include<deque>
using namespace std;


class Solution {
public:
int maxDepth(TreeNode* root) {
    if(root == nullptr) return 0;
    ++_depth;
    _deque.push_back(root);
    while(!_deque.empty())
    {
        swap(_deque, _pre);
        while(!_pre.empty())
        {
            if(_pre.front()->left!=nullptr)
            {
                _deque.push_back(_pre.front()->left);
            }
            if(_pre.front()->right!=nullptr)
            {
                _deque.push_back(_pre.front()->right);
            }
            _pre.pop_front();
        }
        if(!_deque.empty())
        ++_depth;
    }
      
      return _depth;
  }

private:
deque<TreeNode*> _deque;
deque<TreeNode*> _pre;
int _depth = 0;
};