/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>

using namespace std;

// 368ms 74.82% 172.3MB 5.05%
// DFS
// O(N) O(L)
class Solution {
 private:
  vector<int> lastVals;
  bool dfs(TreeNode* u, int lv) {
    // base
    if (!u)
      return true;
    if (u->val % 2 == lv % 2)
      return false;
    lastVals.resize(max((int)lastVals.size(), lv + 1));
    if (lastVals[lv] != 0 &&
        ((lv % 2 == 1 && lastVals[lv] <= u->val) ||
         (lv % 2 == 0 && lastVals[lv] >= u->val ))) {
      return false;
    }
    // recursion
    lastVals[lv] = u->val;    
    return dfs(u->left, lv+1) && dfs(u->right, lv+1);
  }
 public:
  bool isEvenOddTree(TreeNode* root) {
    return dfs(root, 0);
  }
};

// 396ms 65.1% 158.7MB 5.05%
// BFS
// O(N) O(N)
class Solution {
 public:
  bool isEvenOddTree(TreeNode* root) {
    vector<TreeNode*> q; q.push_back(root);
    int lv = -1;
    while (q.size()) {
      ++lv;
      int last = 0;
      vector<TreeNode*> qq;
      for (TreeNode* u : q) {
        if (u->val % 2 == lv % 2)
          return false;
        if (last != 0 &&
            ((lv % 2 == 1 && last <= u->val) ||
             (lv % 2 == 0 && last >= u->val)))
          return false;
        last = u->val;
        if (u->left)
          qq.push_back(u->left);
        if (u->right)
          qq.push_back(u->right);
      }
      swap(q, qq);
    }
    return true;
  }  
};

