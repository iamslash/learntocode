// Copyright (C) 2018 by iamslash
// https://leetcode.com/problems/sum-root-to-leaf-numbers/description/

#include <cstdio>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  explicit TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  explicit TreeNode(int x, TreeNode* l, TreeNode* r) :
      val(x), left(l), right(r) {}
};

class Solution {
 public:
  int m_sum;
  void solve(TreeNode* t, int num, int lv) {
    // recursion
    num = num * 10 + t->val;
    if (t->left)
      solve(t->left, num, lv+1);
    if (t->right)
      solve(t->right, num, lv+1);

    if (t->left == NULL && t->right == NULL)
      m_sum += num;
  }
  int sumNumbers(TreeNode* root) {
    if (root == NULL)
      return 0;
    solve(root, 0, 0);
    return m_sum;
  }
};

int main() {
  TreeNode* root = new TreeNode(4,
                                new TreeNode(9,
                                             new TreeNode(5),
                                             new TreeNode(1)),
                                new TreeNode(0));
  Solution s;
  printf("%d\n", s.sumNumbers(root));
  return 0;
}
