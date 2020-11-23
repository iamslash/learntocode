/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <unordered_map>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  explicit TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  explicit TreeNode(int x, TreeNode* l, TreeNode* r) :
      val(x), left(l), right(r) {}
};

// // 36ms 99.15%
// // dfs with map
// // O(V+E) O(N)
// class Solution {
//  private:
//   std::unordered_map<int, int> m_ump;
//   int dfs(TreeNode* u) {
//     // base
//     if (!u)
//       return 0;
//     // recursion
//     int sum = u->val + dfs(u->left) + dfs(u->right);
//     m_ump[sum]++;
//     return sum;
//   }
//  public:
//   bool checkEqualTree(TreeNode* u) {
//     int sum = dfs(u);
//     return (sum & 1) == 0 &&
//         (sum == 0 ? m_ump[0] > 1 : m_ump[sum/2] > 0);
//   }
// };

// 36ms 99.15% 26MB 99.49%
// dfs
// O(V+E) O(1)
class Solution {
 private:
  bool m_b = false;
  int m_tgt = 0;
  int dfs(TreeNode* u) {
    if (!u)
      return 0;
    int sum = u->val + dfs(u->left) + dfs(u->right);
    if (sum == m_tgt)
      m_b = true;
    return sum;
  }
 public:
  bool checkEqualTree(TreeNode* u) {
    m_tgt = 0;
    int sum = dfs(u);
    if (sum & 1)
      return false;
    m_b = false;
    m_tgt = sum / 2;
    dfs(u->left);
    dfs(u->right);
    return m_b;
  }
};

void printb(bool b) {
  printf("%s\n", b ? "true" : "false");
}

int main() {
  // TreeNode* u = new TreeNode(
  //     5,
  //     new TreeNode(10),
  //     new TreeNode(
  //         10,
  //         new TreeNode(2),
  //         new TreeNode(3)));
  // TreeNode* u = new TreeNode(
  //     1,
  //     new TreeNode(2),
  //     new TreeNode(
  //         10,
  //         new TreeNode(2),
  //         new TreeNode(20)));
  // TreeNode* u = new TreeNode(
  //     1,
  //     NULL,
  //     new TreeNode(2, new TreeNode(3), NULL));
  TreeNode* u = new TreeNode(
      1,
      NULL,
      new TreeNode(2, new TreeNode(3), NULL));
  Solution sln;
  printb(sln.checkEqualTree(u));
  return 0;
}
