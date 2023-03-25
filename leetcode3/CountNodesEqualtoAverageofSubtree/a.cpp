/* Copyright (C) 2023 by iamslash */

#include <cstdio>
#include <array>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 9ms 68.48% 12.1MB 18.44%
// dfs
// O(N) O(lgN)
class Solution {
private:
  int best = 0;
  array<int, 2> dfs(TreeNode* u) {
    // base
    if (u == nullptr) {
      return {0, 0};
    }
    // recursion
    auto lrst = dfs(u->left);
    auto rrst = dfs(u->right);
    int sum = lrst[0] + rrst[0] + u->val;
    int cnt = lrst[1] + rrst[1] + 1;
    if (sum / cnt == u->val) {
      best++;
    }
    return {sum, cnt};
  }
public:
  int averageOfSubtree(TreeNode* root) {
    dfs(root);
    return best;
  }
};

int main() {
  return 0;
}
