/* Copyright (C) 2018 by iamslash */

#include <cstdio>

// O(N) O(1)
struct RandomListNode {
  int label;
  RandomListNode *next, *random;
  explicit RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
  explicit RandomListNode(int x, RandomListNode* n, RandomListNode* r) :
      label(x), next(n), random(r) {}
};

class Solution {
 public:
  RandomListNode *copyRandomList(RandomListNode *h) {
    RandomListNode *r, *p, *q;
    if (h == NULL)
      return NULL;

    // insert between p
    for (p = h; p; p = p->next->next) {
      q = new RandomListNode(p->label);
      q->next = p->next;
      p->next = q;
    }
    r = h->next;

    // set q's random 
    for (p = h; p; p = p->next->next) {
      if (p->random)
        p->next->random = p->random->next;
    }
    
    // seperate brand new nodes
    for (p = h; p; p = p->next) {
      q = p->next;
      p->next = q->next;
      if (q->next)
        q->next = q->next->next;
    }
    return r;
  }
};

#include <cstdio>

int main() {
  
  
  // Solution s;
  // s.copyRandomList(h);
  
  return 0;
}
