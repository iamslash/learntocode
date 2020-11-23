/* Copyright (C) 2018 by iamslash */

#include <cstdio>
#include <queue>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  explicit TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  explicit TreeNode(int x, TreeNode* l, TreeNode* r) :
      val(x), left(l), right(r) {}
};

// BFS
// // 16ms 11.48%
// class Solution {
//  public:
//   int findBottomLeftValue(TreeNode* t) {
//     std::queue<std::pair<int, TreeNode*>> q;
//     q.push({0, t});
//     std::pair<int, TreeNode*> rslt = {0, t};
//     while (!q.empty()){
//       const auto& v = q.front(); q.pop();
//       if (rslt.first < v.first)
//         rslt = v;
//       if (v.second->left)
//         q.push({v.first+1, v.second->left});
//       if (v.second->right)
//         q.push({v.first+1, v.second->right});
//     }
//     return rslt.second->val;
//   }
// };

// DFS
// 8ms 98.72%
class Solution {
 private:
  std::vector<std::vector<int>> m_C;
  void solve(TreeNode* t, int lv) {
    if (t == NULL)
      return;
    if (lv == m_C.size())
      m_C.push_back({});
    m_C[lv].push_back(t->val);
    solve(t->left, lv+1);
    solve(t->right, lv+1);
  }
 public:
  int findBottomLeftValue(TreeNode* t) {
    solve(t, 0);
    return m_C.back().front();
  }
};

int main() {
  // TreeNode* t = new TreeNode(2,
  //                            new TreeNode(1),
  //                            new TreeNode(3));
  TreeNode* t = new TreeNode(1,
                             new TreeNode(2,
                                          new TreeNode(4),
                                          NULL),
                             new TreeNode(3,
                                          new TreeNode(5,
                                                       new TreeNode(7),
                                                       NULL),
                                          new TreeNode(6)));  
  Solution sln;
  printf("%d\n", sln.findBottomLeftValue(t));
  return 0;
}
