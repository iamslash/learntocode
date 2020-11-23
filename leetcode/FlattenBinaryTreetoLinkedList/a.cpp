// Copyright (C) 2018 by iamslash
// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/

#include <cstdio>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  explicit TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  explicit TreeNode(int x, TreeNode* l, TreeNode* r) :
      val(x), left(l), right(r) {}
};

//     1
//    / \
//   2   5
//  / \   \
// 3   4   6
class Solution {
 public:
  void flatten(TreeNode* root) {
    while (root) {
      if (root->left) {
        TreeNode* l = root->left;
        while (l->right)
          l = l->right;
        l->right = root->right;
        root->right = root->left;
        root->left = NULL;
      }
      root = root->right;
    }
  }
};

void printt(TreeNode* t) {
  if (t == NULL) {
    printf("N ");
    return;
  }
  printt(t->left);
  printf("%d ", t->val);
  printt(t->right);
}

int main() {
  TreeNode* t = new TreeNode(1,
                             new TreeNode(2,
                                          new TreeNode(3),
                                          new TreeNode(4)),
                             new TreeNode(5,
                                          NULL,
                                          new TreeNode(6)));
  Solution s;
  s.flatten(t);
  printt(t);
  printf("\n");
  return 0;
}
