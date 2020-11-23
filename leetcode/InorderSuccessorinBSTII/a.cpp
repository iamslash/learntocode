/* Copyright (C) 2019 by iamslash */

#include <cstdio>

class Node {
 public:
  int val;
  Node* left;
  Node* right;
  Node* parent;
};

// 
// 
//            5
//         /     \
//        3       6
//      /   \
//     2     4
//    /
//   1
//
// 1 2
// 2 3
// 3 4
// 4 5
// 5 6
// 6 N

// 712ms 93.80% 84.5MB 100.00%
class Solution {
 public:
  Node* inorderSuccessor(Node* u) {
    if (u->right) {
      // check right child
      Node* r = u->right;
      while (r && r->left)
        r = r->left;
      return r;
    }
    
    // there is parent
    if (u->parent) {
      while (u->parent && u->parent->right == u) {
        u = u->parent;
      }
      return u->parent;
    }

    return NULL;
  }
};

int main() {
  return 0;
}
