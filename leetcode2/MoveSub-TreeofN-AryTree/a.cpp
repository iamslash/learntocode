/* Copyright (C) 2020 by iamslash */

#include <cstdio>

// 88ms 50.81% 28.4MB 96.88%
// tree
// O(N) O(N)
class Solution {
 private:
  Node* getParent(Node* u, Node* v) {
    Node* parent = NULL;
    for (int i = 0; i < u->children.size() && parent == NULL; ++i) {
      if (u->children[i] == v)
        parent = u;
      else
        parent = getParent(u->children[i], v);
    }
    return parent;
  }
  // Remove v in u or replace v with u 
  void removeOrReplace(Node* u, Node* v, Node* r = NULL) {
    // base
    if (u == NULL)
      return;
    // recursion
    for (int i = 0; i < u->children.size(); ++i) {
      if (u->children[i] == v) {
        if (r != NULL) {
          u->children[i] = r;
        } else {
          u->children.erase(u->children.begin() + i);
        }
      }
    }
  }
 public:
  Node* moveSubTree(Node* u, Node* p, Node* q) {
    Node* parentOfPinU = getParent(u, p);
    if (parentOfPinU != q) {
      Node* parentOfQinP = getParent(p, q);
      if (parentOfQinP != NULL) {
        // Remove q from the parent of q
        removeOrReplace(parentOfQinP, q);
      }
      removeOrReplace(parentOfPinU, p, parentOfQinP != NULL ? q : NULL);
      q->children.push_back(p);
    }
    // p should be direct child of q
    if (u == p) {
      return q;
    }
    return u;
  }
};
