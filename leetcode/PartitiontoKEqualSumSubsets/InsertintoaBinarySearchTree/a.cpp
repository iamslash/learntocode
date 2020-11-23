/* Copyright (C) 2019 by iamslash */

#include <cstdio>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  TreeNode(int x, TreeNode* l, TreeNode* r) :
      val(x), left(l), right(r) {}  
};

// 96ms 99.75% 33.2MB 25.35%
// O(lgN) O(1)
class Solution {
 public:
  TreeNode* insertIntoBST(TreeNode* root, int val) {
    // base
    if (root == NULL)
      return new TreeNode(val);

    // recursion
    if (root->val > val)
      root->left = insertIntoBST(root->left, val);
    else
      root->right = insertIntoBST(root->right, val);
    return root;
  }
};

int main() {
  int val = 5;
  TreeNode* root = new TreeNode(4, new TreeNode(2, new TreeNode(1), new TreeNode(3)), new TreeNode(7));
  Solution sln;
  root = sln.insertIntoBST(root, val);  
  return 0;
}
