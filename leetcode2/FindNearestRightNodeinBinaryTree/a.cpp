/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>

using namespace std;

//      1
//    /   \
//  2       3
//   \    /  \
//    4  5    6

// 180ms 76.67% 88.1MB 33.33%
// BFS
// O(N) O(N)
class Solution {
 public:
  TreeNode* findNearestRightNode(TreeNode* root, TreeNode* u) {
    queue<TreeNode*> q;
    q.push(root);
    while (q.size()) {
      TreeNode* last = NULL;
      int n = q.size();
      for (int i = 0; i < n; ++i) {
        TreeNode* f = q.front(); q.pop();
        if (i == n-1 && f == u)
          return NULL;
        if (last == u)
          return f;
        last = f;
        if (f->left)
          q.push(f->left);
        if (f->right)
          q.push(f->right);
      }
    }
    return NULL;
  }
};

// 236ms 6.67% 88.1MB 36.67%
// why ???
class Solution {
 public:
  TreeNode* findNearestRightNode(TreeNode* root, TreeNode* u) {
    queue<TreeNode*> q;
    q.push(root);
    while (q.size()) {
      TreeNode* last = NULL;
      int n = q.size();
      for (int i = 0; i < n; ++i) {
        TreeNode* f = q.front(); q.pop();
        if (i == n-1 && f == u)
          return NULL;
        if (last == u)
          return f;
        last = f;
        if (f->left)
          q.push(f->left);
        if (f->right)
          q.push(f->right);
      }
    }
    return NULL;
  }
};

