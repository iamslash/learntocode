/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <cstdlib>



  //      4
  //    /   \
  //   2     6
  //  / \   / 
  // 3   1 5   

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  explicit TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  explicit TreeNode(int x, TreeNode* l, TreeNode* r) :
      val(x), left(l), right(r) {}
};

// 28ms 0.61%
// 25.4MB 0.65%
// O(N) O(1)
class Solution {
 public:
  TreeNode* addOneRow(TreeNode* root, int v, int d) {
    // base
    if (d <= 1) {
      TreeNode* t = new TreeNode(v);
      if (d)
        t->left = root;
      else
        t->right = root;
      return t;
    }
    // recursion
    if (root && d >= 2) {
      root->left = addOneRow(root->left, v, d > 2 ? d - 1 : 1);
      root->right = addOneRow(root->right, v, d > 2 ? d - 1 : 0);
    }
    return root;
  }
};

void printt(TreeNode* root) {
  if (root == NULL) {
    printf("N ");
    return;
  }
  printf("%d ", root->val);
  printt(root->left);
  printt(root->right);
}

int main() {
  TreeNode* root = new TreeNode(4,
                                new TreeNode(2,
                                             new TreeNode(3),
                                             new TreeNode(1)),
                                new TreeNode(6,
                                             new TreeNode(5),
                                             NULL));
  Solution sln;
  root = sln.addOneRow(root, 1, 2);
  printt(root);
  return 0;
}
