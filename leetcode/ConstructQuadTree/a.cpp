/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>

class Node {
 public:
  bool val;
  bool isLeaf;
  Node* topLeft;
  Node* topRight;
  Node* bottomLeft;
  Node* bottomRight;

  Node() {}

  Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight,
       Node* _bottomLeft, Node* _bottomRight) {
    val = _val;
    isLeaf = _isLeaf;
    topLeft = _topLeft;
    topRight = _topRight;
    bottomLeft = _bottomLeft;
    bottomRight = _bottomRight;
  }
};

class Solution {
 private:
  Node* dfs(std::vector<std::vector<int>>& G, int y, int x, int d) {
    // base
    if (d == 1)
      return new Node(G[y][x] == 1, true, NULL, NULL, NULL, NULL);

    // recursion
    int nd = d / 2;
    Node* tl = dfs(G, y     , x     , nd);
    Node* tr = dfs(G, y     , x + nd, nd);
    Node* bl = dfs(G, y + nd, x     , nd);
    Node* br = dfs(G, y + nd, x + nd, nd);
    // merge
    if (tl->isLeaf && tr->isLeaf && br->isLeaf && bl->isLeaf &&
        ((tl->val && tr->val && bl->val && br->val) ||
         (!tl->val && !tr->val && !bl->val && !br->val))) {
          bool val = tl->val;
          delete tl; tl = NULL;
          delete tr; tr = NULL;
          delete bl; bl = NULL;
          delete br; br = NULL;
          return new Node(val, true, NULL, NULL, NULL, NULL);
    }
    return new Node(true, false, tl, tr, bl, br);
  }
 public:
  Node* construct(std::vector<std::vector<int>>& G) {
    int n = G.size();
    if (n == 0)
      return NULL;
    return dfs(G, 0, 0, n);
  }
};

int main() {
  return 0;
}
