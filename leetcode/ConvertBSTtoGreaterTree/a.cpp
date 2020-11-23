/* Copyright (C) 2019 by iamslash */

#include <cstdio>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 48ms 44.92% 29.2MB 14.29%
// DFS
// O(N) O(lgN)
class Solution {
 private:
  int sum;
 public:
  void dfs(TreeNode* u) {
    if (!u)
      return;
    dfs(u->right);
    sum += u->val;
    u->val = sum;
    dfs(u->left);        
  }
  TreeNode* convertBST(TreeNode* root) {
    dfs(root);
    return root;
  }
};

int main() {
  return 0;
}
