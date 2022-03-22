/* Copyright (C) 2022 by iamslash */

#include <cstdio>
#include <vector>
#include <cstdlib>

using namespace std;

// 120ms 75.00% 30.4MB 46.34%
struct Node {
  Node *next, *down;
  int val;
  Node(Node *next, Node *down, int val):
      next(next), down(down), val(val){}     
};
class Skiplist{
 private:
  Node *head;
  vector<Node*> inserted;
 public:
  Skiplist() {
    head = new Node(NULL, NULL, 0);
  }
    
  bool search(int tgt) {
    Node *p = head;
    while (p) {
      while (p->next && p->next->val < tgt)
        p = p->next;
      if (!p->next || p->next->val > tgt)
        p = p->down;
      else
        return true;
    }
    return false;
  }
    
  void add(int num) {
    inserted.clear();
    Node *p = head;
    while (p) {
      while (p->next && p->next->val < num)
        p = p->next;
      inserted.push_back(p);
      p = p->down;
    }
    Node* downNode = NULL;
    bool insertUp = true;
    while (insertUp && inserted.size()) {
      Node *u = inserted.back();
      inserted.pop_back();
      u->next = new Node(u->next, downNode, num);
      downNode = u->next;
      insertUp = (rand() & 1) == 0;
    }
    if (insertUp) {
      head = new Node(new Node(NULL, downNode, num), head, 0);
    }
  }
    
  bool erase(int num) {
    Node *p = head;
    bool seen = false;
    while (p) {
      while (p->next && p->next->val < num)
        p = p->next;
      if (!p->next || p->next->val > num)
        p = p->down;
      else {
        seen = true;
        p->next = p->next->next;
        p = p->down;
      }
    }
    return seen;
  }
};
