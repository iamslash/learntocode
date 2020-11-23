/* Copyright (C) 2018 by iamslash */

#include <cstdio>
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 private:
  int _maxDepth(TreeNode* node, int depth) {
    // base condition
    if (node == NULL)
      return depth;
    // recursion
    return std::max(_maxDepth(node->left, depth+1),
                    _maxDepth(node->right, depth+1));
  }
 public:
  int maxDepth(TreeNode* root) {
    if (root == NULL)
      return 0;
    return std::max(_maxDepth(root->left, 1),
                    _maxDepth(root->right, 1));
  }
};

int main() {
  return 0;
}
