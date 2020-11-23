/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <queue>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 0ms 100.00% 10.1MB 100.00%
// BFS
// O(N) O(N)
class Solution {
 public:
  bool isCompleteTree(TreeNode* u) {
    std::queue<TreeNode*> q;
    q.push(u);
    bool bnull = false;
    while (q.size()) {
      u = q.front(); q.pop();
      if (!u) {
        bnull = true;
      } else {
        if (bnull)
          return false;
        q.push(u->left);
        q.push(u->right);
      }
    }
    return true;
  }
};

int main() {
  return 0;
}
