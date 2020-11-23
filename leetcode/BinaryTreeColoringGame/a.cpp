/* Copyright (C) 2019 by iamslash */

#include <cstdio>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


// 4ms 78.07% 11.4MB 100.00%
// DFS
class Solution {
 private:
  int m_left = 0;
  int m_right = 0;
  int dfs(TreeNode* u, int x) {
    // base
    if (!u)
      return 0;
    int l = dfs(u->left, x);
    int r = dfs(u->right, x);
    if (u->val == x) {
      m_left = l;
      m_right = r;
    }
    return l + r + 1;
  }
 public:
  bool btreeGameWinningMove(TreeNode* u, int n, int x) {
    dfs(u, x);
    int up = n - m_left - m_right - 1;
    int half = n / 2;
    return up > half || m_left > half || m_right > half;
  }
};

int main() {
  return 0;
}
