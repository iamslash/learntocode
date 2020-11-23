/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 0ms 100.00% 12MB 30.86%
// dfs
// O(V+E) O(V)
class Solution {
 private:
  int m_i;
  std::vector<int> m_ans;
  bool dfs(TreeNode* u, std::vector<int>& v) {
    // base
    if (!u)
      return true;
    if (u->val != v[m_i++])
      return false;

    // recursion
    if (u->left && u->left->val != v[m_i]) {
      m_ans.push_back(u->val);
      return dfs(u->right, v) && dfs(u->left, v);
    }
    return dfs(u->left, v) && dfs(u->right, v);
  }
 public:
  std::vector<int> flipMatchVoyage(
      TreeNode* u,
      std::vector<int>& V) {
    return dfs(u, V) ? m_ans : std::vector<int>{-1};
  }
};

int main() {
  return 0;
}
