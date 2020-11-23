/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <unordered_set>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 44ms 58.68% 26.2MB 35.00%
// DFS, hash
// O(N) O(N)
class Solution {
 private:
  std::unordered_set<int> nums;
  bool dfs(TreeNode* u, int k) {
    // base
    if (!u)
      return false;
    if (nums.count(k - u->val) > 0)
      return true;
    nums.insert(u->val);
    return dfs(u->left, k) || dfs(u->right, k);
  }
 public:
  bool findTarget(TreeNode* u, int k) {
    return dfs(u, k);
  }
};

int main() {
  return 0;
}
