/* Copyright (C) 2018 by iamslash */

#include <cstdio>
#include <vector>
#include <queue>

// 8ms 99.19%
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  explicit TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  explicit TreeNode(int x, TreeNode* l, TreeNode* r) :
      val(x), left(l), right(r) {}
};

class Solution {
 public:
  std::vector<int> largestValues(TreeNode* t) {
    std::vector<int> rslt;
    if (t == NULL)
      return rslt;
    std::queue<std::pair<TreeNode*, int>> q;
    q.push({t, 0});
    rslt.push_back(t->val);
    while (!q.empty()) {
      const auto& pr = q.front(); q.pop();
      if (pr.second >= rslt.size())
        rslt.push_back(pr.first->val);
      rslt[pr.second] = std::max(rslt[pr.second], pr.first->val);
      if (pr.first->left)
        q.push({pr.first->left, pr.second+1});
      if (pr.first->right)
        q.push({pr.first->right, pr.second+1});
    }
    return rslt;
  }
};

int main() {
  TreeNode* t = new TreeNode(1,
                             new TreeNode(3,
                                          new TreeNode(5),
                                          new TreeNode(3)),
                             new TreeNode(2,
                                          NULL,
                                          new TreeNode(9)));
  Solution sln;
  const auto& rslt = sln.largestValues(t);
  for (int a : rslt)
    printf("%d ", a);
  printf("\n");
  
  return 0;
}
