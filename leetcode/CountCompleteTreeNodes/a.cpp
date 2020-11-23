// Copyright (C) 2018 by iamslash
#include <cstdio>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  explicit TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  explicit TreeNode(int x, TreeNode* l, TreeNode* r) :
      val(x), left(l), right(r) {}
};

// // Time exceeded
// class Solution {
//  public:
//   int countNodes(TreeNode* root) {
//     // base condition
//     if (root == NULL)
//       return 0;

//     // recursion
//     int rslt = countNodes(root->left) + countNodes(root->right);
//     if (rslt == 0)
//       return 1;
//     return rslt + 1;
//   }
// };

// Input: 
//     1
//    / \
//   2   3
//  / \  /
// 4  5 6
// Output: 6

// 16 ms
class Solution {
 public:
  int countNodes(TreeNode* root) {
    // base condition
    if (root == NULL || root->val == -1)
      return 0;
    root->val = -1;
    int h = 0;
    TreeNode *l = root, *r = root;
    while (r) {
      h++;
      l = l->left;
      r = r->right;
    }
    // full binary tree
    if (l == NULL)
      return (1 << h) - 1;
    // complete binary tree
    return 1 + countNodes(root->left) + countNodes(root->right);
  }
};

int main() {
  TreeNode* t = new TreeNode(1,
                             new TreeNode(2,
                                          new TreeNode(4),
                                          new TreeNode(5)),
                             new TreeNode(3,
                                          new TreeNode(6),
                                          NULL));
  Solution sln;
  printf("%d\n", sln.countNodes(t));
  return 0;
}
