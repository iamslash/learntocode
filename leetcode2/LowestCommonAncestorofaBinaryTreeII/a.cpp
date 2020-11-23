/* Copyright (C) 2020 by iamslash */

#include <cstdio>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 140ms 89.29% 61.2MB 5.95%
// DFS
// O(N) O(lgN)
class Solution {
 private:
  TreeNode* pp;
  TreeNode* qq;
  TreeNode* dfs(TreeNode* u, TreeNode* p, TreeNode* q) {
    // base
    if (!u)
      return NULL;
    // recursion
    TreeNode* l = dfs(u->left, p, q);
    TreeNode* r = dfs(u->right, p, q);
    if (u == p) {
      pp = u;
      return u;
    }
    if (u == q) {
      qq = u;
      return u;
    }
    if (l && r)
      return u;
    if (l)
      return l;
    return r;
  }
 public:
  TreeNode* lowestCommonAncestor(TreeNode* u, TreeNode* p, TreeNode* q) {
    TreeNode* lca = dfs(u, p, q);
    if (!pp || !qq)
      return NULL;
    return lca;
  }
};
