/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <map>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  TreeNode(int x, TreeNode* l, TreeNode* r) :
      val(x), left(l), right(r) {}
};

// 4ms 100.00% 13.5MB 97.18%
// 2 kinds of dfs
// O(N) O(1)
class Solution {
 private:
  int m_mind = INT_MAX;
  int m_minv;
  int dfs(TreeNode* u, int k) {
    // base
    if (!u)
      return -1;
    if (u->val == k) {
      dfsK(u, 0);
      return 0;
    }
    int l = dfs(u->left, k);
    int r = dfs(u->right, k);
    // k is on left subtree
    if (l >= 0) {
      dfsK(u->right, l + 2);
      return l + 1;
    }
    // k is on right subtree
    if (r >= 0) {
      dfsK(u->left, r + 2);
      return r + 1;
    }
    return -1;
  }
  void dfsK(TreeNode* u, int lv) {
    if (!u)
      return;
    if (!u->left && !u->right) {
      if (lv < m_mind) {
        m_mind = lv;
        m_minv = u->val;
      }
      return;
    }
    dfsK(u->left, lv+1);
    dfsK(u->right, lv+1);    
  }
 public:
  int findClosestLeaf(TreeNode* u, int k) {
    dfs(u, k);
    return m_minv;
  }
};

int main() {
  return 0;
}
