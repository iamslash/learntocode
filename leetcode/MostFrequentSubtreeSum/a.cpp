/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <unordered_map>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  explicit TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  explicit TreeNode(int x, TreeNode* l, TreeNode* r) :
      val(x), left(l), right(r) {}  
};

// 12ms 98.96%
// O(N) O(N)
class Solution {
 private:
  std::unordered_map<int, int> m_ump;
  int m_max_cnt = 0;
  int solve(TreeNode* root) {
    // base
    if (root == NULL)
      return 0;

    // recursion
    int sum = root->val;
    sum += solve(root->left);
    sum += solve(root->right);
    ++m_ump[sum];
    m_max_cnt = std::max(m_max_cnt, m_ump[sum]);
    return sum;
  }
 public:
  std::vector<int> findFrequentTreeSum(TreeNode* root) {
    solve(root);
    
    std::vector<int> rslt;
    for (const auto& pr : m_ump) {
      if (pr.second == m_max_cnt)
        rslt.push_back(pr.first);
    }
    return rslt;
  }
};

int main() {
  TreeNode* t = new TreeNode(1,
                             new TreeNode(5,
                                          new TreeNode(2),
                                          new TreeNode(-3)),
                             new TreeNode(3));
  Solution sln;
  auto rslt = sln.findFrequentTreeSum(t);
  for (int a : rslt)
    printf("%d ", a);
  printf("\n");
  return 0;
}
