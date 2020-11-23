/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <bitset>
#include <iostream>

using namespace std;

// 216ms 94.60% 107.1MB 96.50%
// DFS, bit manipulation
// O(N) O(lgN)
class Solution {
 private:
  int cnt = 0;
  bitset<10> bs;
  void dfs(TreeNode* u) {
    bs.flip(u->val);
    // printf("u: %d, ", u->val);
    // cout << bs << endl;
    // base
    if (!u->left && !u->right && bs.count() <= 1) {
      cnt++;
      bs.flip(u->val);
      return;
    }
    // recursion
    if (u->left)
      dfs(u->left);
    if (u->right)
      dfs(u->right);
    bs.flip(u->val);
  }
 public:
  int pseudoPalindromicPaths (TreeNode* u) {    
    dfs(u);
    return cnt;
  }
};
