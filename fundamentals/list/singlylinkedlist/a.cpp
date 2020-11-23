/* Copyright (C) 2019 by iamslash */

#include <cstdio>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
  ListNode(int x, ListNode *n) : val(x), next(n) {}
};

int main() {

  // insert
  ListNode* u = new ListNode(1);
  u->next = new ListNode(2);

  // delete
  ListNode* p = u;
  while (p->next && p->next->val != 2)
    p = p->next;
  if (p->next)
    p->next = p->next->next;
  
  return 0;
}
