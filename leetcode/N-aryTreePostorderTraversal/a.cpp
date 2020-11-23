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

// 72ms 41.36% 56.9MB 20.00%
// postorder traversal
// O(N) O(N)
class Solution {
 private:
  std::vector<int> rslt;
  void dfs(Node* u) {
    // base
    if (!u)
      return;
    // recursion
    for (Node* v : u->children) {
      dfs(v);
    }
    rslt.push_back(u->val);
  }
 public:
  std::vector<int> postorder(Node* u) {
    dfs(u);
    return rslt;
  }
};

int main() {
  return 0;
}
