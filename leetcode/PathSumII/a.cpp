/* Copyright (C) 2018 by iamslash */
// https://leetcode.com/problems/path-sum-ii/description/

#include <cstdio>
#include <vector>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  explicit TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  explicit TreeNode(int x, TreeNode* l, TreeNode* r) : val(x), left(l), right(r) {}
};

// O(N) O(N)
// 12ms 41.33%
class Solution {
public:
  std::vector<std::vector<int>> m_r;
  std::vector<int> m_c;  // combination
  int m_sum;
  void solve(TreeNode* tn, int sum) {
    // base condition
    if (tn->left == NULL &&
        tn->right == NULL &&
        sum == 0) {
      m_r.push_back(m_c);
      return;
    }
    // printf("%2d : %2d\n", tn->val, sum);
    // recursion
    if (tn->left) {
      m_c.push_back(tn->left->val);
      solve(tn->left, sum - tn->left->val);
      m_c.pop_back();
    }
    if (tn->right) {
      m_c.push_back(tn->right->val);
      solve(tn->right, sum - tn->right->val);
      m_c.pop_back();
    }
  }
  std::vector<std::vector<int>> pathSum(TreeNode* tn, int sum) {
    if (tn == NULL)
      return m_r;
    m_sum = sum;
    m_c.push_back(tn->val);
    solve(tn, sum - tn->val);
    m_c.pop_back();
    return m_r;
  }
};

int main() {
  TreeNode* t = new TreeNode(5,
                             new TreeNode(4,
                                          new TreeNode(11,
                                                       new TreeNode(7),
                                                       new TreeNode(2)),
                                          NULL),
                             new TreeNode(8,
                                          new TreeNode(13),
                                          new TreeNode(4,
                                                       new TreeNode(5),
                                                       new TreeNode(1))));
  Solution s;
  auto r = s.pathSum(t, 22);

  for (auto rr : r) {
    for (int a : rr) {
      printf("%d ", a);
    }
    printf("\n");
  }
  return 0;
}
