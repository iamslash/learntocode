/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <map>

class Node {
 public:
  int val;
  Node* left;
  Node* right;

  Node() {}

  Node(int _val) {
    val = _val;
    left = NULL;
    right = NULL;
  }

  Node(int _val, Node* _left, Node* _right) {
    val = _val;
    left = _left;
    right = _right;
  }
};

// // 92ms 30.75% 27.6MB 18.69%
// class Solution {
//  private:
//   // {min, max}
//   std::pair<Node*, Node*> dfs(Node* u) {
//     // base
//     if (!u)
//       return {NULL, NULL};

//     // recursion
//     auto l = dfs(u->left);
//     auto r = dfs(u->right);

//     if (l.second) {
//       u->left = l.second;
//       l.second->right = u;
//     }
//     if (r.first) {
//       u->right = r.first;
//       r.first->left = u;
//     }

//     Node* pmin = l.first ? l.first : u ;
//     Node* pmax = r.second ? r.second : u;

//     std::pair<Node*, Node*> pr = {pmin, pmax};
//     return pr;
//   }
//  public:
//   Node* treeToDoublyList(Node* u) {
//     if (!u)
//       return NULL;
//     auto pr = dfs(u);
//     Node* pmin = pr.first;
//     Node* pmax = pr.second;
//     pmin->left = pmax;
//     pmax->right = pmin;
//     return pmin;
//   }
// };

// 76ms 99.00% 26.5MB 92.52%
class Solution {
 private:
  Node* m_prv;
  void solve(Node* u) {
    if (!u)
      return;
    solve(u->left);
    m_prv->right = u;
    u->left = m_prv;
    m_prv = u;
    solve(u->right);
  }
 public:
  Node* treeToDoublyList(Node* u) {
    if (!u)
      return NULL;
    Node* pdum = new Node(0, NULL, NULL);
    m_prv = pdum;
    solve(u);
    m_prv->right = pdum->right;
    pdum->right->left = m_prv;
    return pdum->right;
  }
};

int main() {
  Node* u = new Node(4, new Node(2, new Node(1), new Node(3)), new Node(5));
  Solution sln;
  u = sln.treeToDoublyList(u);
  while (u) {
    printf("%d ", u->val);
    u = u->right;
  }
  printf("\n");
  return 0;
}
