/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <stack>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// // 28ms 20.58% 21.5MB 93.33%
// // inorder traversal
// // O(N) O(lgN)
// class Solution {
//  private:
//   int m_kth;
//   int m_n;
//   void dfs(TreeNode* u) {
//     // base
//     if (!u)
//       return;
//     dfs(u->left);
//     m_n--;
//     if (m_n == 0) {
//       m_kth = u->val;
//       return;
//     }
//     dfs(u->right);
//   }
//  public:
//   int kthSmallest(TreeNode* u, int k) {
//     m_n = k;
//     dfs(u);
//     return m_kth;
//   }
// };

// 24ms 50.49% 21.3MB 98.33
// stack
// O(N) O(lgN)
class Solution {
 public:
  int kthSmallest(TreeNode* u, int k) {
    std::stack<TreeNode*> stck;
    TreeNode* p = u;

    while (stck.size() || p) {
      if (p) {
        stck.push(p);
        p = p->left;
      } else {
        TreeNode* v = stck.top(); stck.pop();
        if (--k == 0)
          return v->val;
        p = v->right;
      }
    }
    return -1;
  }
};

int main() {
  return 0;
}
