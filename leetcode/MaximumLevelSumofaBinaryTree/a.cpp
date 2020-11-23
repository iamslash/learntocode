/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <queue>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 204ms 97.37% 72.9MB 100.00%
// BFS
// O(N) O(N)
class Solution {
 public:
  int maxLevelSum(TreeNode* u) {
    int maxlvl = 1, maxval = 0, lvl = 0;
    std::queue<TreeNode*> q;
    q.push(u);
    while (q.size()) {
      int n = q.size(), sum = 0;
      lvl++;
      for (int i = 0; i < n; ++i) {
        u = q.front(); q.pop();
        sum += u->val;
        if (u->left)
          q.push(u->left);
        if (u->right)
          q.push(u->right);
      }
      if (maxval < sum) {
        maxlvl = lvl;
        maxval = sum;
      }
    }
    return maxlvl;
  }
};

int main() {
  return 0;
}
