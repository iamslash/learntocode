/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  TreeNode(int x, TreeNode* l, TreeNode* r) :
      val(x), left(l), right(r) {}
};

// 4ms 100.00% 12.2MB 6.00%
// DFS
// O(N) O(N)
class Solution {
 public:
  std::vector<std::vector<int>> findLeaves(TreeNode* u) {
    // base
    if (!u)
      return {};

    // recursion
    auto l = findLeaves(u->left);
    auto r = findLeaves(u->right);
    int n = std::max((int)l.size(), (int)r.size());
    std::vector<std::vector<int>> rslt(n, std::vector<int>());
    for (int i = 0; i < n; ++i) {
      if (i < l.size()) {
        for (int j = 0; j < l[i].size(); ++j)
          rslt[i].push_back(l[i][j]);
      }
      if (i < r.size()) {
        for (int j = 0; j < r[i].size(); ++j)
          rslt[i].push_back(r[i][j]);
      }
    }
    rslt.push_back({u->val});
    return rslt;
  }
};

int main() {
  TreeNode* u = new TreeNode(1,
                             new TreeNode(2, new TreeNode(4), new TreeNode(5)),
                             new TreeNode(3));
  Solution sln;
  auto r = sln.findLeaves(u);
  for (auto& l : r) {
    for (int a : l)
      printf("%d ", a);
    printf("\n");
  }
  return 0;
}
