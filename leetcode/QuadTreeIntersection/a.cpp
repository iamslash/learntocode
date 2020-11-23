/* Copyright (C) 2020 by iamslash */

#include <cstdio>

class Node {
 public:
  bool val;
  bool isLeaf;
  Node* topLeft;
  Node* topRight;
  Node* bottomLeft;
  Node* bottomRight;

  Node() {}

  Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
    val = _val;
    isLeaf = _isLeaf;
    topLeft = _topLeft;
    topRight = _topRight;
    bottomLeft = _bottomLeft;
    bottomRight = _bottomRight;
  }
};

// 336ms 72.28% 49.7MB 100.00%
// quard tree
// O(N) O(N)
class Solution {
 public:
  Node* intersect(Node* u, Node* v) {
    // base
    if (u->isLeaf && u->val)
      return u;
    if (v->isLeaf && v->val)
      return v;
    if (u->isLeaf && !u->val)
      return v;
    if (v->isLeaf && !v->val)
      return u;
    
    // recursion
    Node* tl = intersect(u->topLeft, v->topLeft);
    Node* tr = intersect(u->topRight, v->topRight);
    Node* bl = intersect(u->bottomLeft, v->bottomLeft);
    Node* br = intersect(u->bottomRight, v->bottomRight);
    int val = tl->val;
    if (tl->isLeaf && tr->isLeaf && bl->isLeaf && br->isLeaf &&
        val == tr->val && val == bl->val && val == br->val) {
      delete tl;
      delete tr;
      delete bl;
      delete br;
      return new Node(val, true, NULL, NULL, NULL, NULL);
    }
    return new Node(false, false, tl, tr, bl, br);
  }
};

int main() {
  return 0;
}
