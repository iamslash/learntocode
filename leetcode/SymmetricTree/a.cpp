/* Copyright (C) 2018 by iamslash */

#include <cstdio>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 private:
  bool _isSymmetric(TreeNode* l, TreeNode* r) {
    if (l == NULL && r == NULL)
      return true;
    if (l == NULL || r == NULL)
      return false;
    return l->val == r->val &&
        _isSymmetric(l->left, r->right) &&
        _isSymmetric(l->right, r->left);
  }
 public:
  bool isSymmetric(TreeNode* root) {
    return _isSymmetric(root, root);
  }
};

int main() {
  return 0;
}
