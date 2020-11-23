/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <algorithm>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 44ms 80.73% 23.5MB 100.00%
// DFS
// O(N) O(lgN)
class Solution {  
 public:
  TreeNode* sufficientSubset(TreeNode* u, int lmt) {
    // base
    if (!u->left && !u->right)
      return u->val < lmt ? NULL : u; 

    // recursion
    lmt -= u->val;
    if (u->left)
      u->left = sufficientSubset(u->left, lmt);
    if (u->right)
      u->right = sufficientSubset(u->right, lmt);
    if (!u->left && !u->right)
      return NULL;
    return u;
  }
};

int main() {
  return 0;
}
