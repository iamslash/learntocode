/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  TreeNode(int x, TreeNode* l, TreeNode* r) :
      val(x), left(l), right(r) {}
};

// // 40ms 8.98% 21.6MB 10.71%
// // O(NlgN) O(N)
// class Solution {
//  private:
//   std::priority_queue<std::pair<double, int>> m_pq;
//   double m_tgt;
//   int m_k;
//   void dfs(TreeNode* u) {
//     // base
//     if (u == NULL)
//       return;

//     // recursion
//     m_pq.push({std::fabs(m_tgt - u->val), u->val});
//     // printf("%lf %d\n", m_pq.top().first, m_pq.top().second);
//     if (m_pq.size() > m_k)
//       m_pq.pop();
//     dfs(u->left);
//     dfs(u->right);
//   }
//  public:
//   std::vector<int> closestKValues(TreeNode* u, double tgt, int k) {
//     m_tgt = tgt;
//     m_k = k;
//     dfs(u);
//     std::vector<int> rslt;
//     while (!m_pq.empty()) {
//       rslt.push_back(m_pq.top().second);
//       m_pq.pop();
//     }
//     return rslt;
//   }
// };


// 24ms 86.53% 21.3MB 28.57%
// O(N) O(K)
class Solution {
 private:
  std::vector<int> m_rslt;
  double m_tgt;
  int m_k;
  void inorder(TreeNode* u) {
    if (u == NULL)
      return;
    
    inorder(u->left);
    
    if (m_rslt.size() < m_k) {
      m_rslt.push_back(u->val);
    } else {
      if (std::abs(m_rslt[0] - m_tgt) > std::abs(u->val - m_tgt)) {
        m_rslt.erase(m_rslt.begin());
        m_rslt.push_back(u->val);
      } else {
        return;
      }
    }

    inorder(u->right);
  }
 public:
  std::vector<int> closestKValues(TreeNode* u, double tgt, int k) {
    m_tgt = tgt;
    m_k = k;
    inorder(u);
    return m_rslt;
  }
};

int main() {
  TreeNode* u = new TreeNode(
      4,
      new TreeNode(
          2,
          new TreeNode(1), new TreeNode(3)),
      new TreeNode(5));
  Solution sln;
  auto r = sln.closestKValues(u, 3.714286, 2);
  for (int a : r)
    printf("%d ", a);
  printf("\n");
  
  return 0;
}
