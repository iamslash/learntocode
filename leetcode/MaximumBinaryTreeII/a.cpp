/* Copyright (C) 2019 by iamslash */

#include <cstdio>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 0ms 100.00% 10.9MB 100.00%
// O(N) O(N)
class Solution {
 public:
  TreeNode* insertIntoMaxTree(TreeNode* u, int val) {
    // base
    if (!u || u->val < val) {
      TreeNode* r = new TreeNode(val);
      r->left = u;
      return r;
    }

    // recursion
    u->right = insertIntoMaxTree(u->right, val);
    return u;
  }
};

int main() {
  return 0;
}
