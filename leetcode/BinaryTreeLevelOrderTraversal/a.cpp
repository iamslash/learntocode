/* Copyright (C) 2018 by iamslash */

#include <cstdio>
#include <vector>
#include <queue>
#include <map>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 public:
  std::vector<std::vector<int>> levelOrder(TreeNode* root) {
    std::vector<std::vector<int>> r;
    std::queue<std::pair<int, TreeNode*>> q; // level, node
    if (root != NULL)
      q.push(std::make_pair(0, root));
    
    while (!q.empty()) {
      int       l = q.front().first;
      TreeNode* n = q.front().second;
      q.pop();
      if (r.size() <= l)
        r.emplace_back();
      r.back().push_back(n->val);
      if (n->left != NULL)
        q.push(std::make_pair(l+1, n->left));
      if (n->right != NULL)
        q.push(std::make_pair(l+1, n->right));
    }
    return r;
  }
};

int main() {
  return 0;
}
