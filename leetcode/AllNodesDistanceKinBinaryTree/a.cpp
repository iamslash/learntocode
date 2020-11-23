/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 8ms 79.46% 15.3MB 70.21%
// double dfs
// O(N) O(N)
class Solution {
 private:
  std::vector<int> m_rslt;
  TreeNode* m_tgt;
  int m_K;
  // dfs before finding target node
  // return: distance from u to m_tgt else -1
  int dfs(TreeNode* u) {
    // base
    if (!u)
      return -1;
    if (u == m_tgt) {
      dfsWithTarget(u, 0);
      return 1;
    }
    // recursion
    int L = dfs(u->left);
    int R = dfs(u->right);
    if (L != -1) {
      if (L == m_K)
        m_rslt.push_back(u->val);
      dfsWithTarget(u->right, L+1);
      return L + 1;
    }
    if (R != -1) {
      if (R == m_K)
        m_rslt.push_back(u->val);
      dfsWithTarget(u->left, R + 1);
      return R + 1;
    }
    return -1;
  }
  // dfs after finding target node
  // dist: distance from K to u
  void dfsWithTarget(TreeNode* u, int dist) {
    // base
    if (!u)
      return;
    if (dist == m_K) {
      m_rslt.push_back(u->val);
      return;
    }
    // recursion
    dfsWithTarget(u->left, dist + 1);
    dfsWithTarget(u->right, dist + 1);
  }
 public:
  std::vector<int> distanceK(TreeNode* root,
                             TreeNode* tgt,
                             int K) {
    m_tgt = tgt;
    m_K = K;
    dfs(root);
    return m_rslt;
  }
};

int main() {
  return 0;
}
