/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <algorithm>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Wrong Answer
// // DFS
// // O(N) O(1)
// class Solution {
//  private:
//   int m_best = 0;
//   int m_cand = 0;
//   void dfs(TreeNode *u, TreeNode *p) {
//     // base
//     if (!u)
//       return;
//     // recursion
//     int diff = 0;
//     if (p) {
//       diff = p->val - u->val;
//       m_cand += diff;
//       m_best = std::max(m_best, std::abs(m_cand));
//     }
//     dfs(u->left, u);
//     dfs(u->right, u);
//     if (p)
//       m_cand -= diff;
//   }
//  public:
//   int maxAncestorDiff(TreeNode* u) {
//     dfs(u, 0);
//     return m_best;
//   }
// };

// 8ms 69.59% 12.6MB 76.04%
// DFS
// O(N) O(1)
class Solution {
 private:
  int dfs(TreeNode* u, int minv, int maxv) {
    if (!u)
      return maxv - minv;
    maxv = std::max(maxv, u->val);
    minv = std::min(minv, u->val);
    int l = dfs(u->left, minv, maxv);
    int r = dfs(u->right, minv, maxv);
    return std::max(l, r);
  }
 public:
  int maxAncestorDiff(TreeNode* u) {
    return dfs(u, 100000, 0);
  }
};

int main() {
  return 0;
}
