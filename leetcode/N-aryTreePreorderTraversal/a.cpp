/* Copyright (C) 2019 by iamslash */

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

// 72ms 36.26% 56.9MB 10.53%
// preorder traversal
// O(N) O(N)
class Solution {
 private:
  std::vector<int> rslt;
  void dfs(Node* u) {
    // base
    if (!u)
      return;
    // recursion
    rslt.push_back(u->val);
    for (Node* v : u->children) {
      dfs(v);
    }
  }
 public:
  std::vector<int> preorder(Node* u) {
    dfs(u);
    return rslt;
  }
};

int main() {
  return 0;
}
