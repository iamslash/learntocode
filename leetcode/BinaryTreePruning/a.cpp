/* Copyright (C) 2018 by iamslash */
// https://leetcode.com/problems/binary-tree-pruning/description/

#include <cstdio>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  explicit TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  explicit TreeNode(int x, TreeNode* l, TreeNode* r) : val(x), left(l), right(r) {}
};

void printt(TreeNode* p) {
  if (p == NULL) {
    printf("null ");
    return;
  }
  printf("%d ", p->val);
  printt(p->left);
  printt(p->right);
}

class Solution {
 public:
  bool _weak(TreeNode* p) {
    if (p == NULL)
      return true;
    if (_weak(p->left))
      p->left = NULL;
    if (_weak(p->right))
      p->right = NULL;
    if (!p->left && !p->right && p->val == 0)
      return true;
    return false;
  }
  TreeNode* pruneTree(TreeNode* root) {
    _weak(root);
    return root;
  }
};

int main() {
  // TreeNode* p = new TreeNode(1,
  //                            NULL,
  //                            new TreeNode(0,
  //                                         new TreeNode(0),
  //                                         new TreeNode(1)));
  TreeNode* p = new TreeNode(1,
                             new TreeNode(0,
                                          new TreeNode(0),
                                          new TreeNode(0)),
                             new TreeNode(1,
                                          new TreeNode(0),
                                          new TreeNode(1)));
  Solution s;

  TreeNode* r = s.pruneTree(p);
  printt(r);
  
  return 0;
}
