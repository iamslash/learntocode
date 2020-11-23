/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <climits>
#include <algorithm>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


// DFS
// 12ms 92.82% 19.4MB 100.00%
// O(N) O(lgN)
class Solution {
 private:
  TreeNode* m_lca;
  int m_maxdepth = 0;
  int dfs(TreeNode* u, int depth) {
    m_maxdepth = std::max(m_maxdepth, depth);

    // base
    if (!u)
      return depth;

    int l = dfs(u->left, depth + 1);
    int r = dfs(u->right, depth + 1);
    if (l == m_maxdepth && r == m_maxdepth)
      m_lca = u;
    
    return std::max(l, r);
  }
 public:
  TreeNode* lcaDeepestLeaves(TreeNode* u) {
    dfs(u, 0);
    return m_lca;
  }
};

int main() {
  return 0;
}
