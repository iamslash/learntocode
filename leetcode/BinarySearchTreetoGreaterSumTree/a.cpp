/* Copyright (C) 2019 by iamslash */

#include <cstdio>


struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 0ms 100.00% 9.1MB 100.00%
class Solution {
 private:
  int dfs(TreeNode *u, int sum) {
    // base
    if (!u)
      return sum;

    // reucursion
    int r = dfs(u->right, sum);
    u->val += r;
    int l = dfs(u->left, u->val);

    return l;
  }
 public:
  TreeNode* bstToGst(TreeNode *u) {
    dfs(u, 0);
    return u;
  }
};

int main() {
  return 0;
}
