#include "alg.h"

bool match(TreeNode *A, TreeNode *B) {
    if (!B) return true;
    if (!A || A->val != B->val) return false;
    return match(A->left, B->left) && match(A->right, B->right);
}

bool isSubStructure(TreeNode *A, TreeNode *B) {
    if (!A || !B) return false;
    return match(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B);
}

int main() {

}