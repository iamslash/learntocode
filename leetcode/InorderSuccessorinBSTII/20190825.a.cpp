/* Copyright (C) 2019 by iamslash */

#include <cstdio>

class Node {
 public:
  int val;
  Node* left;
  Node* right;
  Node* parent;
};

// 736ms 43.22% 84.8MB 50.00%
// recursion
// O(N) O(lgN)
class Solution {
 public:
  Node* inorderSuccessor(Node* u) {
    // right children ???
    if (u->right) {
      u = u->right;
      while (u && u->left) {
        u = u->left;
      }
      return u;
    }

    // parent ???
    Node* p = u->parent;
    while (p && p->right == u) {
      u = p;
      p = p->parent;
    }
    return p;
  }
};

int main() {
  return 0;
}
