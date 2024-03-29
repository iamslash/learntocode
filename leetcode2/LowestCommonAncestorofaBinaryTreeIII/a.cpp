/* Copyright (C) 2024 by iamslash */

#include <cstdio>

using namespace std;

// Definition for a Node.
class Node {
public:
  int val;
  Node* left;
  Node* right;
  Node* parent;
};

// 10ms 67.16% 12.8MB 38.28%
// math
// O(N) O(1)
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

int main() {
  return 0;
}
