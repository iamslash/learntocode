#include <cstdio>

/* Copyright (C) 2019 by iamslash */

#include <cstdio>

struct ListNode {
  int val;
  ListNode *prev;
  ListNode *next;
  ListNode(int x) : val(x), prev(NULL), next(NULL) {}
  ListNode(int x, ListNode *p, ListNode *n) :
           val(x), prev(n), next(n) {}
};

// void DeleteNode(ListNode* node) {
//   node->prev->next = node->next;
//   node->next->prev = node->prev;
// }

// void RecoverNode(ListNode* node) {
//   node->prev->next = node;
//   node->next->prev = node;
// }

int main() {

  // insert
  ListNode* u = new ListNode(2);
  u->prev = new ListNode(1);
  u->prev->next = u;
  
  u->next = new ListNode(3);
  u->next->prev = u;

  // delete 2
  ListNode* p = u->prev;
  while (p && p->val != 2)
    p = p->next;
  if (p) {
    p->prev->next = p->next;
    if (p->next) {
      p->next->prev = p->prev;
    }      
  }
  
  return 0;
}
