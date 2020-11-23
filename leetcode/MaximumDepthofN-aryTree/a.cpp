/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>

class Node {
 public:
  int val;
  std::vector<Node*> children;

  Node() {}

  Node(int _val) {
    val = _val;
  }

  Node(int _val, std::vector<Node*> _children) {
    val = _val;
    children = _children;
  }
};

// 60ms 51.31% 56.1MB 5.00%
// DFS
// O(N) O(N)
class Solution {
 private:
  int maxLv = 0;
  void dfs(Node* u, int lv) {
    // base
    if (!u)
      return;
    maxLv = std::max(maxLv, lv);
    // recursion
    for (int i = 0; i < u->children.size(); ++i) {
      dfs(u->children[i], lv+1);
    }
  }
 public:
  int maxDepth(Node* u) {
    dfs(u, 1);
    return maxLv;
  }
};

int main() {
  return 0;
}
