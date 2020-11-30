/* Copyright (C) 2020 by iamslash */

#include <cstdio>

class Node {
 public:
  int val;
  Node* left;
  Node* right;
  Node* parent;
};

// 4ms 88.64% 8.1MB 86.36%
class Solution {
 private:
  Node* flip(Node* root, Node* u, Node* fromU) {
    Node* p = u->parent;
    u->parent = fromU;
    if (u->left == fromU)
      u->left = NULL;
    if (u->right == fromU)
      u->right = NULL;
    // base
    if (u == root)
      return u;
    // recursion
    if (u->left) {
      u->right = u->left;
    }
    u->left = flip(root, p, u);
    return u;
  }
 public:
  Node* flipBinaryTree(Node* root, Node * leaf) {
    return flip(root, leaf, NULL);
  }
};

// 4ms 88.64% 8MB 97.73%
// tree
class Solution {
 public:
  Node* dfs(Node* u, Node* leaf) {
    if (!u) {
      return NULL;
    }
    
    Node* left = dfs(u->left, leaf);
    Node* right = dfs(u->right, leaf);
    if (u == leaf) {
      u->left = u->parent;
      u->parent = NULL;
    } else if (left) {
      u->left = u->parent;
      u->parent = left;       
    } else if (right) {
      u->right = u->parent ? u->left : NULL;
      u->left = u->parent ? u->parent : u->left;
      u->parent = right;
    }
    return (u == leaf || left || right) ? u : NULL;
  }

  Node* flipBinaryTree(Node* root, Node* leaf) {
    dfs(root, leaf);
    return leaf;
  }
};
