/* Copyright (C) 2020 by iamslash */

#include <cstdio>

//             8
//          /     \
//        3        1
//       /        / \
//      7        9   4
//     /            / \
//    2            5   6
//
// ust: 4 5 6

// 196ms 47.54% 86MB 34.43%
// DFS
// O(N) O(N)
class Solution {
 private:
  unordered_set<TreeNode*> ust;
 public:
  TreeNode* correctBinaryTree(TreeNode* u) {
    // base
    if (!u) {
      return NULL;
    }
    if (u->right != NULL && ust.count(u->right)) {
      return NULL;
    }
    // recursion
    u->right = correctBinaryTree(u->right);
    u->left = correctBinaryTree(u->left);
    ust.insert(u);
    return u;
  }
};

// 180ms 73.77% 75.4MB 83.61%
// BFS
// O(N) O(N)
class Solution {
 public:
  TreeNode* correctBinaryTree(TreeNode* root) {
    unordered_set<TreeNode*> seen;
    queue<TreeNode**> q;
    if (root)
      q.push(&root);
    while (q.size()) {
      auto u = q.front(); q.pop();
      if ((*u)->right) {
        if (seen.count((*u)->right)) {
          *u = NULL;
          break;
        }
        seen.insert((*u)->right);
        q.push(&(*u)->right);
      }
      if ((*u)->left != NULL) {
        seen.insert((*u)->left);
        q.push(&(*u)->left);
      }
    }
    return root;
  }  
};
