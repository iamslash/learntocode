/* Copyright (C) 2020 by iamslash */

#include <cstdio>

using namespace std;

// 16ms 85.71% 10.7MB 84.92%
// LCA
// O(N) o(1)
class Solution {
 public:
  Node* lowestCommonAncestor(Node* p, Node * q) {
    Node *s = p, *t = q;
    while (s != t) {
      s = s == NULL ? q : s->parent;
      t = t == NULL ? p : t->parent;
    }
    return s;
  }
};
