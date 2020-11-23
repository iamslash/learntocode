/* Copyright (C) 2020 by iamslash */

#include <cstdio>

// 732ms 41.80% 164.7MB 17.99%
// DFS
// O(N) O(lgN)
class Solution {
 public:
  TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
    // base
    if (!original)
      return NULL;
    if (original == target)
      return cloned;
    // recursion
    TreeNode* l = getTargetCopy(original->left, cloned->left, target);
    if (l)
      return l;
    return getTargetCopy(original->right, cloned->right, target);
  }
};
