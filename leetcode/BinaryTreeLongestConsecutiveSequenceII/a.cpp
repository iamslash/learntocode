/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <algorithm>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  TreeNode(int x, TreeNode* l, TreeNode* r) :
      val(x), left(l), right(r) {}
};

// 28ms 41.20% 25.8MB 11.11%
// O(N) O(1)
class Solution {
 private:
  int m_maxlen = 0;
  // return: (inc cnt from child to u , dec cnt from child to u)
  std::vector<int> dfs(TreeNode* u) {
    // base
    if (u == NULL)
      return {0, 0};
    // recursion
    int inc = 1, dec = 1;
    if (u->left) {
      auto l = dfs(u->left);
      if (u->val == u->left->val + 1)
        dec = l[1] + 1;
      else if (u->val == u->left->val - 1)
        inc = l[0] + 1;
    }
    if (u->right) {
      auto r = dfs(u->right);
      if (u->val == u->right->val + 1)
        dec = std::max(dec, r[1] + 1);
      else if (u->val == u->right->val - 1)
        inc = std::max(inc, r[0] + 1);
    }
    m_maxlen = std::max(m_maxlen, dec + inc - 1);
    return {inc, dec};
  }
 public:
  int longestConsecutive(TreeNode* u) {
    dfs(u);
    return m_maxlen;
  }
};

int main() {

  // TreeNode* u = new TreeNode(1, new TreeNode(2), new TreeNode(3));
  // TreeNode* u = new TreeNode(2, new TreeNode(1), new TreeNode(3));
  // TreeNode* u = new TreeNode(1, new TreeNode(1), new TreeNode(1));
  TreeNode* u = new TreeNode(3,
                             new TreeNode(1, NULL, new TreeNode(2)),
                             NULL);
  Solution sln;
  printf("%d\n", sln.longestConsecutive(u));
  
  return 0;
}
