// Copyright (C) 2018 by iamslash
#include <cstdio>

struct ListNode {
  int val;
  ListNode *next;
  explicit ListNode(int x) : val(x), next(NULL) {}
  explicit ListNode(int x, ListNode* p) : val(x), next(p) {}
};

void printl(ListNode* h) {
  while (h) {
    printf("%d ", h->val);
    h = h->next;
  }
  printf("\n");
}


// h     
// 1 2 3   5 4
//     p
//           q
class Solution {
 public:
  void reorderList(ListNode* h) {
    if (!h || !h->next)
      return;

    ListNode* p = h, *q = h->next, *r;

    // separate 2 lists
    while (q && q->next) {
      p = p->next;
      q = q->next->next;
    }
    
    ListNode* i = p->next;
    q = i;
    
    // reverse 2nd list
    p->next = NULL;
    p = NULL;    
    while (q) {
      i = q;
      r = q->next;
      q->next = p;
      p = q;
      q = r;      
    }

    // merge 2 lists
    p = h;
    q = i;
    while (q) {
      r = p->next;
      p->next = q;
      p = r;
      r = q->next;
      q->next = p;
      q = r;
    }
  }
};

int main() {
  ListNode* h = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
  Solution s;
  s.reorderList(h);
  printl(h);
  return 0;
}
