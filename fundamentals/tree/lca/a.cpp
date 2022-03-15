/* Copyright (C) 2022 by iamslash */

#include <cstdio>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 26ms 37.54% 14.2MB 59.46%
// lca
// O(N) O(lgN)
class Solution {
public:
  TreeNode* lowestCommonAncestor(TreeNode* u, TreeNode* p, TreeNode* q) {
    // base
    if (u == NULL || u == p || u == q) {
      return u;
    }
    // recursion
    TreeNode* l = lowestCommonAncestor(u->left, p, q);
    TreeNode* r = lowestCommonAncestor(u->right, p, q);
    if (l != NULL && r != NULL) {
      return u;
    }
    return l != NULL ? l : r;
  }
};

int main() {
  return 0;
}
