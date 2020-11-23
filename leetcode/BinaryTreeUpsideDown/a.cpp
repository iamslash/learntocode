/* Copyright (C) 2019 by iamslash */

#include <cstdio>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  explicit TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  explicit TreeNode(int x, TreeNode* l, TreeNode* r) : val(x), left(l), right(r) {}
};

// 4ms 100.00% 8.9MB 43.48%
class Solution {
 public:
  TreeNode* upsideDownBinaryTree(TreeNode* u) {
    if (!u || !u->left)
      return u;
    TreeNode* l = u->left;
    TreeNode* r = u->right;
    TreeNode* v = upsideDownBinaryTree(u->left);

    l->right = u;
    l->left = r;
    u->left = NULL;
    u->right = NULL;

    return v;
  }
};

void printt(TreeNode* u) {
  if (u == NULL) {
    printf("N ");
    return;
  }
  printf("%d ", u->val);
  printt(u->left);
  printt(u->right);
}

int main() {
  TreeNode* u = new TreeNode(
      1,
      new TreeNode(2, new TreeNode(4), new TreeNode(5)),
      new TreeNode(3));
  Solution sln;

  printt(u);
  // printt(sln.upsideDownBinaryTree(u));
  
  return 0;
}
