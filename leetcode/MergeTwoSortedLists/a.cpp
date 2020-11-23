/* Copyright (C) 2019 by iamslash */

#include <cstdio>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

// 12ms 11.01% 8.9MB 74.59%
class Solution {
 public:
  ListNode* mergeTwoLists(ListNode* u, ListNode* v) {
    ListNode h(0);
    ListNode* p = &h;
    while (u || v) {
      if (u && v) {
        if (u->val < v->val) {
          p->next = u;
          u = u->next;
        } else {
          p->next = v;
          v = v->next;
        }
        p = p->next;
        continue;
      } 
      if (u) {
        p->next = u;
        u = u->next;
      }
      if (v) {
        p->next = v;
        v = v->next;
      }
      p = p->next;
    }
    return h.next;
  }
};

// 4ms 98.91% 8.9MB 86.07%
class Solution {
 public:
  ListNode* mergeTwoLists(ListNode* u, ListNode* v) {
    if (!u || v && u->val > v->val)
      std::swap(u, v);
    if (u)
      u->next = mergeTwoLists(u->next, v);
    return u;
  }
};

int main() {
  return 0;
}
