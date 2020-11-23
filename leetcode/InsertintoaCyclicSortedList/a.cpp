/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <climits>

class Node {
 public:
  int val;
  Node* next;

  Node() {}

  Node(int _val, Node* _next) {
    val = _val;
    next = _next;
  }
};

void printl(Node* h) {
  printf("%d ", h->val);
  Node* p = h->next;  
  while (p != h) {
    printf("%d ", p->val);
    p = p->next;
  }
}

// 84ms 99.58% 29.6MB 56.59%
// O(N) O(1)
class Solution {
 public:
  Node* insert(Node* h, int val) {
    // if (h)
    //   printl(h);
      
    if (!h) {
      h = new Node(val, NULL);
      h->next = h;
      return h;
    }
    Node* b = h;
    Node* p = h->next;
    while (p != h) {
      // printf("%d %d\n", b->val, p->val);
      if ((b->val <= val && val <= p->val) ||
          (b->val > p->val && (val >= b->val || val <= p->val)))
          break;
      b = p;
      p = p->next;
    }
    b->next = new Node(val, p);
    return h;
  }
};

int main() {
  Node* h = new Node();
  h->val = 3;
  h->next = new Node(4, new Node(1, h));
  printl(h);

  Solution sln;
  h = sln.insert(h, 2);
  // printl(h);
  return 0;
}
