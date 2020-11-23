// Copyright (C) 2017 by iamslash

// You get binary tree.
// You should print out all nodes of specified level.
// ex) binary tree is
//             4
//          /    \
//       2         6
//     /  \       /  \
//   1    3   5      7
//  if level is 2, then 2, 6. if level is 3, then 1, 3, 5, 7
// Source : from Amazon

// g++ a.cpp -std=c++11 -o a.exe

// Time Complexity : O(N)
// Space Complexity : O(1)

#include <cstdio>
#include <queue>
#include <cmath>

class Node {
 public:
  int m_n_val;
  Node* m_p_left;
  Node* m_p_right;
  Node(int n_val, Node* p_left, Node* p_right) {
    m_n_val = n_val;
    m_p_left = p_left;
    m_p_right = p_right;
  }
};

void solve(Node* p_node, int n_lv) {
/*
           4
         /   \
        2     6
       /     / 
      1     5   
      
*/
  // BFS                
                // n_lv // 1
  int n_depth = 1;      // 1
  std::queue<Node*> q;  // 2 6
  std::queue<Node*> qq; // 
  q.push(p_node);
  while (n_lv > 1 && !q.empty() && n_depth < n_lv) {
    Node* p_cur = q.front(); q.pop();
    if (p_cur->m_p_left != NULL)
      qq.push(p_cur->m_p_left);
    if (p_cur->m_p_right != NULL)
      qq.push(p_cur->m_p_right);
    if (q.empty()) {
      n_depth++;
      std::swap(q, qq);
    }
  }
  while (!q.empty()) {
    Node* p = q.front(); q.pop();
    printf("%d ", p->m_n_val);
  }
  printf("\n");
}

int main() {
  Node* root = new Node(4,
                        new Node(2,
                                 new Node(1, NULL, NULL), NULL),
                        new Node(6,
                                 new Node(5, NULL, NULL), NULL));
  solve(root, 1);
  solve(root, 2);
  solve(root, 3);
  return 0;
}
