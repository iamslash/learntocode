/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>



   //      25
   //     /  \
   //   1      3
   //  / \    / \
   // 1   3  0   2       

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// // 12ms 79.89% 19.5MB 96.71%
// class Solution {
//  private:
//   std::string m_best;
//   std::string m_cand;
//   void dfs(TreeNode* u) {
//     // base
//     if (!u)
//       return;

//     m_cand += 'a' + u->val;
//     if (!u->left && !u->right) {
//       if (m_best.empty() ||
//           std::lexicographical_compare(m_cand.rbegin(), m_cand.rend(),
//                                        m_best.begin(), m_best.end())) {
//         m_best.clear();
//         m_best.append(m_cand.rbegin(), m_cand.rend());
//       }
//       //printf("%s %s\n", m_cand.c_str(), m_best.c_str());     
//       m_cand.pop_back();  
//       return;
//     }
    
//     // recursion
//     dfs(u->left);
//     dfs(u->right);
//     m_cand.pop_back();
//   }
//  public:
//   std::string smallestFromLeaf(TreeNode* u) {
//     dfs(u);
//     return m_best;
//   }
// };

// 16ms 55.69% 19.8MB 57.24%
// O(N) O(N)
class Solution {
 private:
  std::string m_best;
  void dfs(TreeNode* u, std::string s) {
    // base
    if (!u)
      return;
    s = (char)('a' + u->val) + s;
    if (!u->left && !u->right) {
      if (m_best.empty() || s < m_best)
        m_best = s;
      return;
    }
    // recursion
    dfs(u->left, s);
    dfs(u->right, s);
  }
 public:
  std::string smallestFromLeaf(TreeNode* u) {
    dfs(u, "");
    return m_best;
  }
};

int main() {
  return 0;
}
