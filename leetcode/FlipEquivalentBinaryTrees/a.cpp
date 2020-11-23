/* Copyright (C) 2019 by iamslash */

#include <cstdio>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 4ms 82.20% 11.5MB 94.49%
// O(N) O(N)
class Solution {
 public:
  bool flipEquiv(TreeNode* u, TreeNode* v) {
    // base
    if (!u && !v)
      return true;
    if (!u || !v || u->val != v->val)
      return false;

    // recursion
    return (flipEquiv(u->left, v->left) && flipEquiv(u->right, v->right)) ||
        (flipEquiv(u->left, v->right) && flipEquiv(u->right, v->left));
  }
};

int main() {
  return 0;
}
