// Copyright (C) 2018 by iamslash
// https://leetcode.com/explore/interview/card/google/67/sql-2/473/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


          //     5
          //    / \
          //   4   5
          //  / \   \
          // 1   1   5

#include <cstdio>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  TreeNode(int x, TreeNode* pleft, TreeNode* pright) {
    val = x;
    left = pleft;
    right = pright;
  }
};

class Solution {
public:
  int maxcnt = 0;
  void _solve(TreeNode* pnode, int pval) {
    if (pnode->val == pval)
      maxcnt++;
    else
      maxcnt = 0;
    if (pnode->left)
      _solve(pnode->left, pnode->val);
    if (pnode->right)
      _solve(pnode->right, pnode->val);
  }
  int longestUnivaluePath(TreeNode* pnode) {
    if (pnode == NULL)
      return 0;
    if (pnode->left)
      _solve(pnode->left, pnode->val);
    if (pnode->right)
      _solve(pnode->right, pnode->val);
    return maxcnt;
  }
};

int main() {
  TreeNode* proot = new TreeNode(5,
                                 new TreeNode(4,
                                              new TreeNode(1),
                                              new TreeNode(1)),
                                 new TreeNode(5,
                                              NULL,
                                              new TreeNode(5)));
  Solution s;
  printf("%d\n", s.longestUnivaluePath(proot));
  return 0;
}
