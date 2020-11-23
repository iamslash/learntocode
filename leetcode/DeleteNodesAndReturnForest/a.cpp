/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <unordered_set>
#include <set>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// // 28ms 44.12% 18.9MB 100.00%
// // DFS
// // O(N) O(N)
// class Solution {
//  private:
//   TreeNode* dfs(TreeNode* u,
//            TreeNode* p,
//            std::unordered_set<int>& todel,
//            std::vector<TreeNode*>& rslt) {
//     // base
//     if (!u)
//       return NULL;
//     bool bdel = todel.count(u->val);
//     if (!p && !bdel)
//       rslt.push_back(u);
//     p = bdel ? NULL : u;
//     // recursion
//     u->left  = dfs(u->left, p, todel, rslt);
//     u->right = dfs(u->right, p, todel, rslt);
//     return bdel ? NULL : u;
//   }
//  public:
//   std::vector<TreeNode*> delNodes(
//       TreeNode* u,
//       std::vector<int>& todel) {
//     std::vector<TreeNode*> rslt;
//     std::unordered_set<int> usttodel(todel.begin(), todel.end());
//     dfs(u, NULL, usttodel, rslt);
//     return rslt;
//   }
// };

// 24ms 72.43%
// DFS
// O(N) O(N)
class Solution {
 private:
  std::set<int> m_todel;
  std::vector<TreeNode*> m_ans;
  void dfs(TreeNode*& u) {
    if (!u)
      return;
    dfs(u->left);
    dfs(u->right);
    if (m_todel.count(u->val) == 0)
      return;
    if (u->left)
      m_ans.push_back(u->left);
    if (u->right)
      m_ans.push_back(u->right);
    u = NULL;
    delete u;
  }
 public:
  std::vector<TreeNode*> delNodes(
      TreeNode* u,
      std::vector<int>& todel) {
    for (int i = 0; i < todel.size(); ++i)
      m_todel.insert(todel[i]);
    dfs(u);
    if (u)
      m_ans.push_back(u);
    return m_ans;
  }
};

int main() {
  return 0;
}
