/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <queue>

// Definition for a Node.
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

// 64ms 95.86% 56.9MB 5.55%
// BFS
// O(N) O(N)
class Solution {
 public:
  std::vector<std::vector<int>> levelOrder(Node* root) {
    if (root == NULL)
      return {};
    std::vector<std::vector<int>> r;
    std::queue<Node*> q;
    q.push(root);

    while (q.size()) {
      int n = q.size();
      r.push_back(std::vector<int>());
      for (int i = 0; i < n; ++i) {
        Node* u = q.front(); q.pop();
        r.back().push_back(u->val);
        for (Node* v : u->children) {
          q.push(v);
        }
      }
    }

    return r;
  }
};

int main() {
  return 0;
}
