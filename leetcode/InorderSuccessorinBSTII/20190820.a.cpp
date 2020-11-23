/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <map>

class Node {
public:
  int val;
  Node* left;
  Node* right;
  Node* parent;
};

// 748ms 91.40% 84.9MB 6.56%
// O(N) O(N)
class Solution {
 public:
  Node* inorderSuccessor(Node* u) {
    // check right child
    if (u->right) {
      u = u->right;
      while (u->left)
        u = u->left;
      return u;
    }
    
    // check parent
    Node* p = u->parent;
    while (p && p->right == u) {
      u = p;
      p = u->parent;
    }
    return p;
  }
};

int main() {
  return 0;
}
