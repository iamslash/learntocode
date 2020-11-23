/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <queue>
#include <algorithm>
#include <cstdint>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  TreeNode(int x, TreeNode* l, TreeNode* r) :
      val(x), left(l), right(r) {}  
};

// // root-ord : root-ord, left-ord : root-ord * 2, right-ord : root-ord * 2 + 1
// // 16ms 77.67% 16.6MB 36.11%
// // DFS
// // O(N) O(N)
// // Runtime Error
// class Solution {
//  private:
//   int mod = 1e9+7;
//  private:
//   std::vector<std::pair<int, int>> m_vec;
//   int solve(TreeNode* root, int lvl, int ord) {    
//     if (!root)
//       return 0;
//     if (m_vec.size() == lvl)
//       m_vec.push_back({ord, ord});
//     else
//       m_vec[lvl].second = ord;
//     return std::max({
//         m_vec[lvl].second - m_vec[lvl].first + 1,
//         solve(root->left, lvl + 1, (2 * ord) % mod ),
//         solve(root->right, lvl + 1, (2 * ord + 1) % mod )
//       });
//   }
//  public:
//   int widthOfBinaryTree(TreeNode* root) {
//     return solve(root, 0, 1);
//   }
// };

// 12ms 100.00%
// BFS
// O(N) O(N)
class Solution {
 public:
  int widthOfBinaryTree(TreeNode* root) {
    int mod = 1e9+7;
    if (!root)
      return 0;
    int rslt = 0;
    std::queue<std::pair<TreeNode*, int>> q;
    q.push({root, 1});
    while (!q.empty()) {
      int l = q.front().second;  // left most order
      int r = l;                 // right most order
      int n = q.size();
      for (int i = 0; i < n; ++i) {
        TreeNode* u = q.front().first;
        r = q.front().second;
        q.pop();
        if (u->left)
          q.push({u->left, (r * 2) % mod });
        if (u->right)
          q.push({u->right, (r * 2 + 1) % mod });        
      }
      rslt = std::max(rslt, r + 1 - l);
    }
    return rslt;
  }
};

int main() {

  TreeNode* root = new TreeNode(1,
                                new TreeNode(3, new TreeNode(5), new TreeNode(3)),
                                new TreeNode(2, NULL, new TreeNode(9)));
  Solution sln;
  printf("%d\n", sln.widthOfBinaryTree(root));
  
  return 0;
}
