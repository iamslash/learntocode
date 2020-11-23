// Copyright (C) 2018 by iamslash
// https://leetcode.com/explore/interview/card/top-interview-questions-hard/118/trees-and-graphs/844/

#include <cstdio>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  explicit TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  explicit TreeNode(int x, TreeNode* l, TreeNode* r) :
      val(x), left(l), right(r) {}
};

// 16ms 57.64%
// O(N) O(1)
class Solution {
 public:
  TreeNode* lowestCommonAncestor(TreeNode* t, TreeNode* p, TreeNode* q) {
    // base condition
    if (t == NULL)
      return NULL;
    else if (t == p || t == q)
      return t;

    // recursion
    TreeNode* l = lowestCommonAncestor(t->left, p, q);
    TreeNode* r = lowestCommonAncestor(t->right, p, q);
    if (l != NULL && r != NULL)
      return t;
    
    return l != NULL ? l : r;
  }
};

int main() {
  return 0;
}
