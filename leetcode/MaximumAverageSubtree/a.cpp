/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <map>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 20ms 56.09% 22.2MB 50.00%
// DFS
// O(N) O(lgN)
class Solution {
 private:
  double m_maxavg = 0;
  // return: {sum, cnt}
  std::pair<int, int> dfs(TreeNode* u) {
    // base
    if (!u)
      return {0, 0};
    //
    auto l = dfs(u->left);
    auto r = dfs(u->right);
    int sum = l.first + r.first + u->val;
    int cnt = l.second + r.second + 1;
    double avg = static_cast<double>(sum) / cnt;
    m_maxavg = std::max(m_maxavg, avg);
    return {sum, cnt};
  }
 public:
  double maximumAverageSubtree(TreeNode* u) {
    dfs(u);
    return m_maxavg;
  }
};

int main() {
  return 0;
}
