/* Copyright (C) 2018 by iamslash */

#include <cstdio>

class Node {
 public:
  int val;
  Node* prev;
  Node* next;
  Node* child;

  explicit Node(int _val) {
    val = _val;
    prev = NULL;
    next = NULL;
    child = NULL;
  }

  explicit Node(int _val, Node* _prev, Node* _next, Node* _child) {
    val = _val;
    prev = _prev;
    next = _next;
    child = _child;
  }
};

// Input:
//  1---2---3---4---5---6--NULL
//          |
//          7---8---9---10--NULL
//              |
//              11--12--NULL

// Output:
// 1-2-3-7-8-11-12-9-10-4-5-6-NULL
// 36ms 52.18%
class Solution {
 public:
  Node* flatten(Node* head) {
    for (Node* h = head; h; h = h->next) {
      if (h->child) {
        Node* next_o = h->next;
        h->next = h->child;
        h->next->prev = h;
        h->child = NULL;
        Node* p = h->next;
        while (p->next)
          p = p->next;
        p->next = next_o;
        if (next_o)
          next_o->prev = p;
      }
    }
    return head;
  }
};

int main() {
  Node* p1 = new Node(1);
  Node* p2 = new Node(2);
  Node* p3 = new Node(3);
  Node* p7 = new Node(7);

  p1->next = p2; p2->prev = p1;
  p2->next = p3; p3->prev = p2;
  p3->child = p7; p7->prev = p3;

  Solution sln;
  Node* pp = sln.flatten(p1);
  
  return 0;
}
